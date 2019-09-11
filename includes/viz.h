/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 09:51:11 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/09 16:57:33 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZ_H
# define VIZ_H

# include "lem_in.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL2_gfxPrimitives.h>

//Header for visualizer
# define WIDTH 1920
# define HEIGHT 1080
# define ROOM_W 100
# define ROOM_H 100

typedef struct		s_moves
{
	char			*move;
	struct s_moves	*next;
}					t_moves;

typedef struct 		s_viz
{
	SDL_Window		*window;
	SDL_Renderer	*rend;
	SDL_Texture		*ant;
	SDL_Texture		*room;
	SDL_Texture		*bg;
	int				close;

}					t_viz;

/*
** Init functions for SDL textures/windows/renderer and struct
*/

t_viz				*init_viz(void);
SDL_Window			*init_window(t_viz *viz);
SDL_Renderer		*init_renderer(t_viz *viz);
SDL_Texture			*init_texture(t_viz *viz, char *img_path);
void				populate_viz(t_viz *viz);

/*
** Free and Error print functions
*/

void				viz_error_free(t_viz *viz, const char *error);
void				viz_free(t_viz **viz);

/*
** Event Loop
*/

void				event_loop(t_viz *viz, t_rooms **info, t_moves *moves);
void				event_check(t_viz *viz, t_moves *moves);

/*
** Main type funcs
*/

t_rooms				*read_info(t_rooms **info);

/*
** Drawing of links, rooms, ants
*/

void				draw_links(t_viz *viz, t_rooms **info);
void				draw_rooms(t_viz *viz, t_rooms **info);
void				draw_ants(t_viz *viz, t_rooms **info);
void				draw_bg(t_viz *viz);

#endif
