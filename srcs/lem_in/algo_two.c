/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:42:34 by jhansen           #+#    #+#             */
/*   Updated: 2020/01/14 12:31:45 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** Prints relevant info. L + Ant name
** Sets the ants next room
** Sets the ants current room to the new one
*/

void	execute(t_ant *curr_ant)
{
	ft_putchar('L');
	ft_putnbr(curr_ant->ant_num);
	ft_putchar('-');
	curr_ant->path = curr_ant->path->next;
	curr_ant->curr_path = curr_ant->path->name;
}

/*
** If the ant is not in the end room: Then once the room is found where
** the ant is meant to go to it checks if the room is empty
** or if it's the end room then: sets current room ant count to the count -1.
** Prints the action. Sets the new room ant count to count +1.
** Finally it prints the current path
*/

void	display_ants(t_ant *ant, t_rooms **rooms)
{
	t_rooms *temp;

	temp = *rooms;
	while (temp && temp->end != 1)
		temp = temp->next;
	if (!ft_strequ(temp->name, ant->curr_path))
	{
		temp = *rooms;
		while (!ft_strequ(temp->name, ant->path->next->name))
			temp = temp->next;
		if (temp->ant_count == 0 || temp->end == 1)
		{
			temp = *rooms;
			while (!ft_strequ(temp->name, ant->curr_path))
				temp = temp->next;
			temp->ant_count -= 1;
			execute(ant);
			temp = *rooms;
			while (!ft_strequ(temp->name, ant->curr_path))
				temp = temp->next;
			temp->ant_count += 1;
			ft_putstr(ant->curr_path);
			ft_putchar(' ');
		}
	}
}
