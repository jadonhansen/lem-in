/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 09:51:11 by cdiogo            #+#    #+#             */
/*   Updated: 2020/01/14 10:43:25 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZ_H
# define VIZ_H

# include "lem_in2.h"
# include "/homes/jhansen/.brew/include/SDL2/SDL.h"
# include "/homes/jhansen/.brew/include/SDL2/SDL_image.h"
# include "/homes/jhansen/.brew/include/SDL2/SDL_timer.h"
# include "/homes/jhansen/.brew/include/SDL2/SDL2_gfxPrimitives.h"

# define WIDTH 1920
# define HEIGHT 1080
# define ROOM_W 100
# define ROOM_H 100

# define KEY_Q event.key.keysym.scancode == SDL_SCANCODE_Q
# define KEY_N event.key.keysym.scancode == SDL_SCANCODE_N
# define KEY_R event.key.keysym.scancode == SDL_SCANCODE_R

# define HEX_W 0xFF00FF00
# define ID {stringColor(viz->rend, dims.x + 80, dims.y - 20, ant->id, HEX_W);}
# define CURR_X ant->current->pos.x
# define CURR_Y ant->current->pos.y
# define PREV_X ant->previous->pos.x
# define PREV_Y ant->previous->pos.y
# define DX {dims.x = (PREV_X - (ROOM_W / 2) + (CURR_X - PREV_X) * perc);}
# define DY {dims.y = (PREV_Y - (ROOM_H / 2) + (CURR_Y - PREV_Y) * perc);}
# define DXX {dims.x = ant->current->pos.x - (ROOM_W / 2);}
# define DYY {dims.y = ant->current->pos.y - (ROOM_H / 2);}
# define DIMS {DXX DYY ID}
# define DIMS_2 {DX DY ID}
# define RE {SDL_RenderCopy(viz->rend, viz->ant, NULL, &dims); ant = ant->next;}
# define R_NAME {r_name = ft_strchr(viz->curr_turn->move[i], '-'); r_name += 1;}
# define UP_ANT {update_ant(ants, ant_id, r_name, info);free(ant_id);}
# define PRINTPLUS {ft_putendl_col_fd(MAGENTA, "^^^ Complete", 1);i++;}
# define UP_PLUS {UP_ANT PRINTPLUS}

typedef struct		s_moves
{
	char			**move;
	struct s_moves	*next;
}					t_moves;

typedef struct		s_viz
{
	SDL_Window		*window;
	SDL_Renderer	*rend;
	SDL_Texture		*ant;
	SDL_Texture		*room;
	SDL_Texture		*bg;
	int				close;
	int				active;
	double			percent;
	t_moves			*curr_turn;
}					t_viz;

typedef struct		s_ants
{
	char			*id;
	t_room			*current;
	t_room			*previous;
	struct s_ants	*next;
}					t_ants;

/*
** Init functions for SDL textures/windows/renderer and struct
*/

t_viz				*init_viz(void);
SDL_Window			*init_window(t_viz *viz);
SDL_Renderer		*init_renderer(t_viz *viz);
SDL_Texture			*init_texture(t_viz *viz, char *img_path);
void				populate_viz(t_viz *viz, t_moves **move);

/*
** Free and Error print functions
*/

void				viz_error_free(t_viz *viz, const char *error);
void				viz_free(t_viz **viz);

/*
** Event Loop
*/

void				event_loop(t_viz *viz, t_room **info, t_moves **moves,
																t_ants **ant);
void				event_check(t_viz *viz, t_moves **moves, t_ants **ant,
																t_room **info);
void				update_perc(t_viz *viz, t_ants **ants);

/*
** Helper funcs
*/

int					v_populate_map(char **mappy, t_room **room,
															t_moves **moves);
int					id_length(char *line);

/*
** Drawing of links, rooms, ants
*/

void				draw_links(t_viz *viz, t_room **info);
void				draw_rooms(t_viz *viz, t_room **info);
void				draw_ants(t_viz *viz, t_ants **ants, double perc);
void				draw_bg(t_viz *viz);
void				draw_master(t_viz *viz, t_ants **ant, t_room **info);

/*
** Move struct funcs
*/

t_moves				*init_moves(t_moves **moves, char *line);
void				moves_free(t_moves **moves);

/*
** Ants
*/

t_ants				*init_ant(t_ants **ant, t_room **info, int id);
t_ants				*populate_ants(t_room **info, t_ants **ant);
void				ants_free(t_ants **ants);
void				update_ant(t_ants **ants, char *ant_id, char *room_name,
																t_room **info);

/*
** Parsing of moves
*/

void				parse_move(t_ants **ants, t_room **info, t_viz *viz);
void				reset_moves(t_moves *moves, t_ants **ants, t_room **info,
																t_viz *viz);

/*
** Other Funcs
*/

void				disp_map(char **map);
void				disp_ants(t_ant *ant, t_room **rooms);
t_links				*new_link(t_room *room, char *name);
void				add_link(t_room **room, char *name1, char *name2);
void				free_links(t_links **link);
void				free_paths(t_path **path);
t_path				*new_path(char *room_name);
t_path				*add_path(t_path **path, char *room_name);
size_t				path_length(t_path *path);
t_room				*new_room(char **info, int type);
t_room				*add_room(t_room **room, char **info, int type);
void				free_rooms(t_room **room);
t_room				*find_start(t_room **rooms);
void				room_swap(t_room **rooms);
void				traversal(t_path *path, t_room **rooms);
t_room				*find_room(t_room *room, char *name);
void				validate(char *s, char **mappy, int mode, t_room **room);
int					populate_map(char **mappy, t_room **room);
void				set_ants(char **mappy, t_room **rooms);
void				val_ants(char *s, char **mappy, t_room **room);
t_room				*val_room(char *s, char **mappy, int type, t_room **room);
void				link_check(char **link, t_room **room);
void				val_link(char *s, char **mappy, t_room **room);

#endif
