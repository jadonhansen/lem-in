/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_drawing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:21:56 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/09 16:58:05 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"

/*
** Draws the links between rooms
*/

void		draw_links(t_viz *viz, t_rooms **info)
{
	//linked to Cameron's struct atm
	t_room	*room;
	t_room	*room2;
	t_links	*tmp;

	room = *info;
	// thickLineColor(viz->rend, x, y, x2, y2, 5, 0xFFFFFFFF);
	// printf("%d, %d\n", room->pos.x,room->pos.y);
	// stringColor(viz->rend, room->pos.x, room->pos.y, ".", 0xFFFFFF00);
	while (room)
	{
		tmp = room->links;
		while (tmp)
		{
			room2 = tmp->room;
			thickLineColor(viz->rend, (room->pos.x ), (room->pos.y ), (room2->pos.x ), (room2->pos.y ), 5, 0xFFFFFF00);
			tmp = tmp->next;
		}
		room = room->next;
	}
}

/*
** Draws the rooms
*/

void		draw_rooms(t_viz *viz, t_rooms **info)
{
	//linked to Cameron's struct atm
	t_room		*room;
	SDL_Rect	dims;

	dims.w = ROOM_W;
	dims.h = ROOM_H;
	room = *info;
	while (room)
	{
		dims.x = room->pos.x - (ROOM_W/2);
		dims.y = room->pos.y - (ROOM_H/2);
		SDL_RenderCopy(viz->rend, viz->room, NULL, &dims);
		room = room->next;
	}
}

/*
** Draws the ants prior to the moves, and after each move
*/

void		draw_ants(t_viz *viz, t_rooms **info)
{
	
}

/*
** Draws the background
*/

void		draw_bg(t_viz *viz)
{
	SDL_Rect	dims;

	dims.w = WIDTH;
	dims.h = HEIGHT;
	dims.x = 0;
	dims.y = 0;
	SDL_RenderCopy(viz->rend, viz->bg, NULL, &dims);
}
