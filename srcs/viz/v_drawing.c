/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_drawing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:21:56 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/20 10:51:35 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <viz.h>

/*
** Draws the links between rooms
*/

void		draw_links(t_viz *viz, t_room **info)
{
	t_room	*room;
	t_room	*room2;
	t_links	*tmp;

	room = *info;
	while (room)
	{
		tmp = room->links;
		while (tmp)
		{
			room2 = tmp->room;
			thickLineColor(viz->rend, (room->pos.x), (room->pos.y),
			(room2->pos.x), (room2->pos.y), 8, 0x69420FFF);
			tmp = tmp->next;
		}
		room = room->next;
	}
}

/*
** Draws the rooms
*/

void		draw_rooms(t_viz *viz, t_room **info)
{
	t_room		*room;
	SDL_Rect	dims;

	dims.w = ROOM_W;
	dims.h = ROOM_H;
	room = *info;
	while (room)
	{
		dims.x = room->pos.x - (ROOM_W / 2);
		dims.y = room->pos.y - (ROOM_H / 2);
		if (room->type == 1)
			stringColor(viz->rend, dims.x, dims.y - 20, "START", 0xFFFFFFFF);
		else if (room->type == 2)
			stringColor(viz->rend, dims.x, dims.y - 20, "END", 0xFFFFFFFF);
		else
			stringColor(viz->rend, dims.x, dims.y - 20, room->name, 0xFFFFFFFF);
		SDL_RenderCopy(viz->rend, viz->room, NULL, &dims);
		room = room->next;
	}
}

/*
** Draws the ants prior to the moves, and after/during each move
*/

void		draw_ants(t_viz *viz, t_ants **ants, double perc)
{
	t_ants		*ant;
	SDL_Rect	dims;

	// https://stackoverflow.com/questions/22745076/libpng-warning-iccp-known-incorrect-srgb-profile
	dims.w = 500 / 5;
	dims.h = 500 / 5;
	ant = *ants;
	while (ant)
	{
		if (!viz->active)
		{
			DIMS;
		}
		else if (viz->active)
		{
			if (ant->previous)
			{
				DIMS_2;
			}
			else
			{
				DIMS;
			}
		}
		RE;
	}
}

/*
** Draws the background image
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

/*
** Calls all draw functions at once. Also clears the renderer and renders
** what has been drawn
*/

void		draw_master(t_viz *viz, t_ants **ant, t_room **info)
{
	SDL_RenderClear(viz->rend);
	draw_bg(viz);
	draw_links(viz, info);
	draw_rooms(viz, info);
	draw_ants(viz, ant, viz->percent);
	SDL_RenderPresent(viz->rend);
}
