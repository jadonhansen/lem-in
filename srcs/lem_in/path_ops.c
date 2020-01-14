/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 13:24:34 by jhansen           #+#    #+#             */
/*   Updated: 2020/01/14 12:34:13 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** Reverses path direction so that it can used to navigate with
*/

void		path_correction(t_path **path)
{
	t_path *curr;
	t_path *previous;
	t_path *next;

	curr = *path;
	previous = NULL;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = previous;
		previous = curr;
		curr = next;
	}
	*path = previous;
}

/*
** Creates path node from room name
*/

t_path		*create_node(char *name)
{
	t_path	*node;

	node = (t_path *)malloc(sizeof(t_path));
	if (node)
	{
		node->name = ft_strdup(name);
		node->next = NULL;
		return (node);
	}
	return (NULL);
}

/*
** Adds path node to the struct
*/

void		add_path(t_path **path, char *room)
{
	t_path	*temp;
	t_path	*node;

	temp = *path;
	if (temp)
	{
		node = create_node(room);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
	else
		*path = create_node(room);
}

/*
** Free's struct
*/

void		free_path(t_path **path)
{
	t_path *next;

	if (path)
	{
		while (*path)
		{
			next = (*path)->next;
			free((*path)->name);
			free(*path);
			*path = next;
		}
		*path = NULL;
	}
}
