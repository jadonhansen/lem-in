/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 08:40:20 by cdiogo            #+#    #+#             */
/*   Updated: 2019/10/06 14:05:18 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# define MAX 2147483647
# define MIN -2147483648

# include <stdio.h>		//DEBUGGING

/*
** Macros
*/

enum					e_error_codes
{
	NO_ANTS = 1,
	DUP_ROOM,
	DUP_XY,
	DUP_LINK,
	NO_START_OR_END,
	NO_X,
	NO_Y,
	BAD_INPUT,
	BAD_COMMAND,
	EMPTY_LINE,
	ERROR,
	NON_EXISTING_LIST,
	NON_EXISTING_ROOM,
	TOO_MANY_ANTS,
	NO_LINK,
	PATH_ERROR
};

typedef struct			s_content
{
	char				*content;
	struct s_content	*next;
}						t_content;

typedef struct			s_links
{
	char				*name;
	struct s_rooms		*room;
	struct s_links		*next;
}						t_links;

typedef struct			s_rooms
{
	char				*name;
	int					x;
	int					y;
	int					start;
	int					end;
	int					occupied;
	int					weight;
	t_links				*links;
	struct s_rooms		*next;
	struct s_rooms		*prev;
}						t_rooms;

typedef struct			s_queue
{
	t_rooms				*room;
	struct s_queue		*next;
}						t_queue;

typedef struct			s_path
{
	char				*name;
	struct s_path		*next;
}						t_path;

/*
**	Reading & Basic Error Checks of Input
*/

t_rooms					*read_map(void);
void					check_line(char *line, t_content **file);
int						word_manager(char *line, int words);
int						word_count(char *str);
int						is_command(char *line);
int						is_comment(char *line);
int						is_room(char *line);
int						is_link(char *line);
int						is_ant(char *line);
int						all_digits_check(char *str);
int						dash_check(char *str);
char					*whitespace_remover(char *str, int type, t_content **file);

/*
**	Erroring
*/

void					free_rooms_error(t_rooms **node, int msg);
void					free_content_error(t_content **node, int msg);
void					error_out(int code);

/*
**	Advanced Error Checking
*/

int						advanced_check_and_fill(t_content **file, t_rooms **head);
int						check_for_ant(t_content **head);
int						duplicate_rooms(t_rooms **rooms);
int						double_check(char *current, char *temp);
int						duplicate_link(t_content **file);
int						is_endstart(t_rooms **rooms);
int						existing_room(t_content **file, t_rooms **head);
int						dup_link_check(t_links **head, char *link);

/*
**	Algorithm functions
*/

void					bigboy_algo(t_rooms **room_head);
int						path_find(t_rooms **room_head);
t_path					*generate_path(t_rooms *room_head);
void					generate_moves(t_rooms **room_head);

/*
**	t_path function
*/

void					path_correction(t_path **path);
void					add_path(t_path **path, char *room);
void					free_path(t_path **path);

/*
**	t_queue functions
*/

t_queue					*queue_node(t_rooms *room);
void					queue_add(t_queue *queue, t_rooms *room);
t_rooms					*find_start(t_rooms **rooms);
void					queue_remove(t_queue **queue);
void					free_queue(t_queue **queue);

/*
**  t_content functions
*/

t_content				*init_content(t_content **file, char *line);
void					print_content(t_content **head);
void					free_content(t_content **head);

/*
**	t_rooms functions
*/

t_rooms					*filler(t_content **file, t_rooms **head);
t_rooms					*init_rooms(t_rooms **head, char *s, int val);
t_rooms					*find_room(t_rooms *room, char *name);
void					match_room(t_rooms **head, char *room, char *link);
void					init_links(t_content **file, t_rooms **head);
void                	free_links(t_links **links);
void					free_rooms(t_rooms **head);


void					print_rooms(t_rooms **head);		//debug
void					print_path(t_path **path);			//debug

#endif
