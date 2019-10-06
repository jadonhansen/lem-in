/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_viz.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 12:17:02 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/20 09:58:20 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <viz.h>

/*
** Initializes the viz struct
*/

t_viz			*init_viz(void)
{
	t_viz	*viz;

	if (!(viz = (t_viz*)malloc(sizeof(t_viz))))
		viz_error_free(NULL, "viz failed to init");
	viz->window = NULL;
	viz->rend = NULL;
	viz->bg = NULL;
	viz->ant = NULL;
	viz->room = NULL;
	viz->close = 0;
	viz->active = 0;
	viz->percent = 0;
	viz->curr_turn = NULL;
	return (viz);
}

/*
** Initializes the SDL Window and returns pointer to it
*/

SDL_Window		*init_window(t_viz *viz)
{
	SDL_Window	*win;

	if (!(win = SDL_CreateWindow("Lem-in Visualizer",
						SDL_WINDOWPOS_CENTERED,
						SDL_WINDOWPOS_CENTERED,
						WIDTH, HEIGHT, 0)))
		viz_error_free(viz, SDL_GetError());
	return (win);
}

/*
** Initializes the SDL Renderer and returns pointer to it
*/

SDL_Renderer	*init_renderer(t_viz *viz)
{
	SDL_Renderer	*ren;
	int				flags;

	flags = SDL_RENDERER_ACCELERATED;
	if (!(ren = SDL_CreateRenderer(viz->window, -1, flags)))
		viz_error_free(viz, SDL_GetError());
	return (ren);
}

/*
** Initializes an SDL Texture and returns pointer to it
*/

SDL_Texture		*init_texture(t_viz *viz, char *img_path)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = IMG_Load(img_path);
	texture = SDL_CreateTextureFromSurface(viz->rend, surface);
	SDL_FreeSurface(surface);
	if (!texture)
		viz_error_free(viz, SDL_GetError());
	return (texture);
}

/*
** Populates the viz struct with pointers for reference in the visualizer
*/

void			populate_viz(t_viz *viz, t_moves **move)
{
	viz->window = init_window(viz);
	viz->rend = init_renderer(viz);
	viz->bg = init_texture(viz, "srcs/viz/resources/bg.jpg");
	viz->ant = init_texture(viz, "srcs/viz/resources/ant500.png");
	viz->room = init_texture(viz, "srcs/viz/resources/sq.png");
	viz->curr_turn = *move;
}
