/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_ants.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <cdiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:26:11 by cdiogo            #+#    #+#             */
/*   Updated: 2020/01/06 14:18:18 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"

/*
** Creates a node and returns it
*/

static t_ants	*create_node(t_room **info, int id)
{
	t_ants		*node;
	char		*num;

	node = (t_ants*)malloc(sizeof(t_ants));
	if (node)
	{
		num = ft_itoa(id);
		node->id = ft_strjoin("L", num);
		node->current = *info;
		node->previous = NULL;
		node->next = NULL;
		free(num);
	}
	return (node);
}

/*
** Adds node to the end of a list
*/

static void		add_tail(t_ants **head, t_ants *node)
{
	t_ants	*tmp;

	if (!(head) || (!(node)))
		return ;
	tmp = *head;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

/*
** Initializes the ants struct and add nodes to the end of the list.
*/

t_ants			*init_ant(t_ants **ant, t_room **info, int id)
{
	t_ants	*head;
	t_ants	*node;

	head = *ant;
	if (head)
	{
		node = create_node(info, id);
		add_tail(&head, node);
	}
	else
		head = create_node(info, id);
	return (head);
}

/*
** Populates each node of the ant list with appropriate data.
*/

t_ants			*populate_ants(t_room **info, t_ants **ant)
{
	t_ants	*ant_head;
	t_room	*info_head;
	int		id;

	id = 1;
	ant_head = *ant;
	info_head = *info;
	while (id <= info_head->ant_count)
	{
		ant_head = init_ant(&ant_head, info, id);
		id++;
	}
	return (ant_head);
}

/*
** Frees the contents of the ants linked list and the strjoin pointer
** within each node.
*/

void			ants_free(t_ants **ants)
{
	t_ants	*current;
	t_ants	*next;

	current = *ants;
	if (current)
	{
		while (current)
		{
			next = current->next;
			free(current->id);
			free(current);
			current = next;
		}
		*ants = NULL;
	}
}
