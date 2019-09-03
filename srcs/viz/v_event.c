/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_event.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:03:28 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/03 16:24:43 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"

/*
** Looks for key input, for the purpose of closing the visualizer or executing
** a turn.
*/

void		event_check(t_viz *viz, t_moves *moves)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_Quit)
			viz->close = 1;
		if (event.key.keysym.scancode == SDL_SCANCODE_Q)
			viz->close = 1;
		if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
		{
			//Move ants when space is pressed.
		}
	}
}

/*
** Loop that's responsible for: Redrawing rooms, links and ants each turn 
*/

void		event_loop(t_viz *viz, t_rooms *info, t_moves *moves)
{
	//TODO
	while (!(viz->close))
	{
		//stuff
		draw_links();
		draw_rooms();
		draw_ants();
		ft_putendl("Hello!");
		check_event(viz, moves);
	}
}
