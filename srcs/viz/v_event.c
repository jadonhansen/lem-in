/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_event.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:03:28 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/09 16:56:26 by cdiogo           ###   ########.fr       */
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

void		event_loop(t_viz *viz, t_rooms **info, t_moves *moves)
{
	//TODO
	while (!(viz->close))
	{
		//stuff
		SDL_RenderClear(viz->rend);
		draw_bg(viz);
		draw_links(viz, info);
		draw_rooms(viz, info);
		// draw_ants(viz, info);
		SDL_RenderPresent(viz->rend);
		SDL_Delay(1000 / 120);
		event_check(viz, moves);
	}
}
