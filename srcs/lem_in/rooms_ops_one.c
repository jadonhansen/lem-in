/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_ops_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:20:31 by cdiogo            #+#    #+#             */
/*   Updated: 2019/10/06 13:55:27 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static t_rooms		*create_node(char *line, int xcoord, int ycoord, int val)
{
	t_rooms	*node;

	node = (t_rooms*)malloc(sizeof(t_rooms));
	if (node)
	{
		node->name = line;
		node->x = xcoord;
		node->y = ycoord;
		node->links = NULL;
		node->weight = 0;
		node->occupied = 0;
		if (val == 1)
		{
			node->start = 1;
			node->end = 0;
		}
		else if (val == 2)
		{
			node->start = 0;
			node->end = 1;			
		}
		else
		{
			node->start = 0;
			node->end = 0;			
		}
		node->prev = NULL;
		node->next = NULL;
	}
	return (node);
}

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

t_rooms		*init_rooms(t_rooms **head, char *s, int val)
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

void		print_rooms(t_rooms **head)		//debugging
{
	t_rooms	*temp;
	t_links	*temp_l;

	temp = *head;
	if (temp)
	{
		while (temp != NULL)
		{
			ft_putstr("NAME:  ");
			ft_putstr_col_fd(CYAN, temp->name, 1);
			ft_putchar('\n');
			ft_putstr("LINKS: ");
			if (temp->links)
			{
				temp_l = temp->links;
				while (temp_l != NULL)
				{
					if (temp_l->name)
						ft_putstr_col_fd(GREEN, temp_l->name, 1);
					if (temp_l->next != NULL)
						ft_putstr(", ");
					temp_l = temp_l->next;
				}
			}
			ft_putstr("\nX: ");
			ft_putnbr_col_fd(BLUE, temp->x, 1);
			ft_putstr("\nY: ");
			ft_putnbr_col_fd(BLUE, temp->y, 1);
			ft_putstr("\nWeight:");
			ft_putnbr_col_fd(RED, temp->weight, 1);
			ft_putchar('\n');
			if (temp->start == 1)
			{
				ft_putstr("START: ");
				ft_putnbr_col_fd(YELLOW, temp->start, 1);
				ft_putchar('\n');
			}
			else
				printf("START: %d\n", temp->start);
			if (temp->end == 1)
			{
				ft_putstr("END:   ");
				ft_putnbr_col_fd(YELLOW, temp->end, 1);
				ft_putstr("\n\n");
			}
			else
				printf("END:   %d\n\n", temp->end);
			temp = temp->next;
		}
	}
	else
	{
		printf("No list\n");
		exit (1);
	}
}
