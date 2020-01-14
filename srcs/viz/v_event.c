/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_event.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <cdiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:03:28 by cdiogo            #+#    #+#             */
/*   Updated: 2020/01/06 14:18:54 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"

/*
** Looks for key input, for the purpose of closing the visualizer, executing
** a turn or resetting the moves.
*/

void	event_check(t_viz *viz, t_moves **moves, t_ants **ants, t_room **info)
{
	SDL_Event	event;
	t_ants		*tmp;

	while (SDL_PollEvent(&event))
	{
		if ((event.type == SDL_KEYDOWN && KEY_Q) || event.type == SDL_QUIT)
			viz->close = 1;
		if (event.type == SDL_KEYDOWN && KEY_R && !viz->active)
			reset_moves(*moves, ants, info, viz);
		if (event.type == SDL_KEYDOWN && KEY_N && !viz->active)
		{
			tmp = *ants;
			while (tmp->next)
				tmp = tmp->next;
			if (tmp->current->type == 2)
				return ;
			viz->active = 1;
			parse_move(ants, info, viz);
		}
	}
}

/*
** Loop responsible for: Redrawing rooms, links and ants each turn, as well as
** calling functions to check for keyboard events and update animation values.
*/

void	event_loop(t_viz *viz, t_room **info, t_moves **moves, t_ants **ant)
{
	viz->percent = 0.01;
	while (!(viz->close))
	{
		draw_master(viz, ant, info);
		SDL_Delay(1000 / 60);
		update_perc(viz, ant);
		event_check(viz, moves, ant, info);
	}
}

/*
** Updates the percent value for smooth animations, also has a check to prevent
** ant "resetting" to the previous room once it reaches end room.
*/

void	update_perc(t_viz *viz, t_ants **ants)
{
	t_ants	*tmp;

	tmp = *ants;
	if (viz->active && viz->percent < 1)
		viz->percent += 0.01;
	else if (viz->active)
	{
		viz->active = 0;
		viz->percent = 0.01;
		while (tmp)
		{
			if (tmp->current->type == 2)
				tmp->previous = tmp->current;
			tmp = tmp->next;
		}
	}
}
