/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <cdiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:59:29 by cdiogo            #+#    #+#             */
/*   Updated: 2020/01/06 14:19:59 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"

/*
** Creates a node and returns it
*/

static t_moves	*create_node(char *line)
{
	t_moves	*node;

	node = (t_moves*)malloc(sizeof(t_moves));
	if (node)
	{
		node->move = ft_strsplit(line, ' ');
		node->next = NULL;
	}
	return (node);
}

/*
** Adds node to the end of a list
*/

static void		add_tail(t_moves **head, t_moves *node)
{
	t_moves	*tmp;

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
** Initializes the moves struct and add nodes to the end of the list.
*/

t_moves			*init_moves(t_moves **moves, char *line)
{
	t_moves	*head;
	t_moves	*node;

	head = *moves;
	if (head)
	{
		node = create_node(line);
		add_tail(&head, node);
	}
	else
		head = create_node(line);
	return (head);
}

/*
** Frees the contents of the moves linked list and the double array held
** within each node.
*/

void			moves_free(t_moves **moves)
{
	t_moves *current;
	t_moves	*next;

	current = *moves;
	if (current)
	{
		while (current)
		{
			next = current->next;
			ft_free_array(current->move);
			free(current);
			current = next;
		}
		*moves = NULL;
	}
}
