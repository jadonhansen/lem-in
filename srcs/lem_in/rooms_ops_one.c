/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_ops_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:20:31 by cdiogo            #+#    #+#             */
/*   Updated: 2020/01/14 12:35:02 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** Creates room node from relevant data
*/

static t_rooms		*create_node(char *line, int xcoord, int ycoord, int val)
{
	t_rooms	*node;

	if ((node = (t_rooms*)malloc(sizeof(t_rooms))))
	{
		node->name = line;
		node->x = xcoord;
		node->y = ycoord;
		node->links = NULL;
		node->weight = 0;
		node->ant_count = 0;
		if (val == 1)
		{
			START_NODE;
		}
		else if (val == 2)
		{
			END_NODE;
		}
		else
			NODE;
		node->prev = NULL;
		node->next = NULL;
	}
	return (node);
}

/*
** Adds room to the bottom of the room struct
*/

static void			add_tail(t_rooms **head, t_rooms *node)
{
	t_rooms	*tmp;

	if (!(head) || (!(node)))
		return ;
	tmp = *head;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		node->prev = tmp;
	}
}

/*
** Manages the creation of the room nodes. Retrieves relevant data
** from each line passed as *s
*/

t_rooms				*init_rooms(t_rooms **head, char *s, int val)
{
	t_rooms	*node;
	char	**arr;
	int		x;
	int		y;

	arr = ft_strsplit(s, ' ');
	x = ft_atol(arr[1]);
	y = ft_atol(arr[2]);
	if (*head)
	{
		node = create_node(arr[0], x, y, val);
		add_tail(head, node);
	}
	else
		*head = create_node(arr[0], x, y, val);
	free(arr[1]);
	free(arr[2]);
	free(arr);
	return (*head);
}

/*
** Puts all ants in the starting room
*/

void				set_ants(t_rooms **rooms, t_content **content)
{
	t_rooms		*temp;
	t_content	*file;

	file = *content;
	temp = *rooms;
	while (temp && temp->start != 1)
		temp = temp->next;
	temp->ant_count = ft_atol(file->content);
}
