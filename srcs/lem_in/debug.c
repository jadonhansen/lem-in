/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:53:52 by cdiogo            #+#    #+#             */
/*   Updated: 2020/01/14 11:49:04 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** Prints room struct and all structs within. Used for debug purposes
*/

void		print_rooms(t_rooms **head)
{
	t_rooms	*temp;
	t_links	*temp_l;

	temp = *head;
	if (temp)
	{
		while (temp != NULL)
		{
			ft_putstr("NAME:  ");
			ft_putendl_col_fd(CYAN, temp->name, 1);
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
			ft_putstr("\nNum of ants:");
			ft_putnbr_col_fd(RED, temp->ant_count, 1);
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
		exit(1);
	}
}
