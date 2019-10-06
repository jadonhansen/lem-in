/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_ops_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:15:28 by jhansen           #+#    #+#             */
/*   Updated: 2019/10/06 13:54:42 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_rooms				*find_room(t_rooms *room, char *name)
{
	while (room)
	{
		if (ft_strequ(room->name, name))
			return (room);
		room = room->next;
	}
	return (room);
}

int				dup_link_check(t_links **head, char *link)
{
	t_links	*temp;

	temp = *head;
	if (temp && link)
	{
		while (temp != NULL)
		{
			if (ft_strequ(temp->name, link))
				return (1);
			temp = temp->next;
		}
	}
	return (0);
}

static t_links		*create_node(t_rooms *room, char *line)
{
	t_links	*node;

	node = (t_links *)malloc(sizeof(t_links));
	if (node)
	{
		node->name = ft_strdup(line);
		node->next = NULL;
		node->room = find_room(room, node->name);
	}
	return (node);
}

void			match_room(t_rooms **head, char *room, char *link)
{
	t_rooms	*node;
	t_links	*tmp_link;

	node = *head;
	while (node && !ft_strequ(node->name, room))
		node = node->next;
	if (node)
	{
		if (!(node->links))
		{
			node->links = create_node((*head), link);
			return ;
		}
		if (dup_link_check(&node->links, link) == 0)
		{
			tmp_link = node->links;
			while (tmp_link->next)
				tmp_link = tmp_link->next;
			tmp_link->next = create_node((*head), link);
		}
	}
}

void			init_links(t_content **file, t_rooms **head)
{
	t_content	*temp;
	char		**arr;

	temp = *file;
	if (*file && *head)
	{
		while (temp != NULL)
		{
			if ((word_count(temp->content) == 1) && is_link(temp->content))
			{
				arr = ft_strsplit(temp->content, '-');
				match_room(head, arr[0], arr[1]);
				match_room(head, arr[1], arr[0]);
				free(arr[0]);
				free(arr[1]);
				free(arr);
			}
			temp = temp->next;
		}
	}
}
