/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:42:34 by jhansen           #+#    #+#             */
/*   Updated: 2019/12/04 13:43:26 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void    execute(t_ant *curr_ant)
{
    ft_putchar('L');
    ft_putnbr(curr_ant->ant_num);
    ft_putchar('-');
    curr_ant->path = curr_ant->path->next;
    curr_ant->curr_path = curr_ant->path->name;
}

void    display_ants(t_ant *ant, t_rooms **rooms)
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