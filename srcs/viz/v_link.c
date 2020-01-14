/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_link.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <cdiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:01:45 by bmarks            #+#    #+#             */
/*   Updated: 2020/01/14 11:36:32 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in2.h"

/*
** Creates and returns a new link
*/

t_links	*new_link(t_room *room, char *name)
{
	t_links *new;

	new = (t_links *)malloc(sizeof(t_links));
	if (!new)
		MAL_ERROR;
	new->link = ft_strdup(name);
	new->room = find_room(room, new->link);
	new->next = NULL;
	return (new);
}

/*
** Adds a new link to the list
*/

void	add_link(t_room **room, char *name1, char *name2)
{
	t_room	*tmp;
	t_links	*tmp_link;

	tmp = *room;
	while (tmp && !ft_strequ(name1, tmp->name))
		tmp = tmp->next;
	if (tmp)
	{
		if (!(tmp->links))
		{
			tmp->links = new_link((*room), name2);
			return ;
		}
		tmp_link = tmp->links;
		while (tmp_link->next)
		{
			ft_strequ(tmp_link->link, name2) ? (DUP_LINK) : NULL;
			tmp_link = tmp_link->next;
		}
		if (ft_strequ(tmp_link->link, name2))
			DUP_LINK;
		tmp_link->next = new_link((*room), name2);
	}
}

/*
** Frees the list of links
*/

void	free_links(t_links **link)
{
	t_links *next;

	next = *link;
	while (*link)
	{
		next = (*link)->next;
		free((*link)->link);
		free(*link);
		(*link) = next;
	}
	*link = NULL;
}
