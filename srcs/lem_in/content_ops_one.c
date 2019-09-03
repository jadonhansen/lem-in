/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_ops_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:21:07 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/03 15:42:44 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static t_content	*create_node(char *line)
{
	t_content	*node;

	node = (t_content *)malloc(sizeof(t_content));
	if (node)
	{
		node->content = ft_strdup(line);
		node->next = NULL;
	}
	return (node);
}

static void			add_tail(t_content **head, t_content *node)
{
	t_content	*tmp;

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

t_content			*init_content(t_content **file, char *line)
{
	t_content	*node;
	t_content	*head;

	head = *file;
	if (head)
	{
		node = create_node(line);
		add_tail(&head, node);
	}
	else
	{
		head = create_node(line);
	}
	return (head);
}

void				print_content(t_content **head)
{
	t_content	*node;

	node = *head;
	if (node)
	{
		while (node)
		{
			ft_putendl_col_fd(CYAN, node->content, 1); //remove colour printing
			node = node->next;
		}
	}
}
