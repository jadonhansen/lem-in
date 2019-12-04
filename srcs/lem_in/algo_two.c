/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:42:34 by jhansen           #+#    #+#             */
/*   Updated: 2019/12/04 12:40:34 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void    execute(t_ant *curr_ant)
{
    ft_putchar('L');
    ft_putnbr(curr_ant->ant_num);       // prints respective characters and ant number
    ft_putchar('-');
    curr_ant->path = curr_ant->path->next;      //changes the ants current room to the one it moved to
    curr_ant->curr_path = curr_ant->path->name; //changed current room name to the new one its on
}

void    display_ants(t_ant *ant, t_rooms **rooms)
{
    t_rooms *temp;

    temp = *rooms;
    while (temp && temp->end != 1)      //finds end room
        temp = temp->next;
    if (!ft_strequ(temp->name, ant->curr_path))     //prints only if not at the end room
    {
        temp = *rooms;
        while (!ft_strequ(temp->name, ant->path->next->name))       //finds the next room that the ant needs to move to
            temp = temp->next;
        if (temp->ant_count == 0 || temp->end == 1)     //exeutes if the next rooms ant count is 0 or if its the end room(conatins multiple ants)
        {
            temp = *rooms;
            while (!ft_strequ(temp->name, ant->curr_path))      //finds current path/room its in
                temp = temp->next;
            temp->ant_count -= 1;       //makes ant counts less by one at that room
            execute(ant);               //prints movement
            temp = *rooms;
            while (!ft_strequ(temp->name, ant->curr_path))      //finds current path/room its in (changed in execute function)
                temp = temp->next;
            temp->ant_count += 1;           //makes the ant count in the new room + 1
            ft_putstr(ant->curr_path);      //prints new position
            ft_putchar(' ');
        }
    }
}