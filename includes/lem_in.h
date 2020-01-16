/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 08:40:20 by cdiogo            #+#    #+#             */
/*   Updated: 2020/01/16 14:51:34 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

/*
** Macros
*/

# define MAX 2147483647
# define MIN -2147483648

# define ERRNOANT {error_out(NO_ANTS);return (0);}
# define ERR2ANT {error_out(TOO_MANY_ANTS);return (0);}
# define ERRDUPLINK {error_out(DUP_LINK);return (0);}
# define ANT_MAX {error_out(INT_MAX);return(0);}
# define FREEEXIT {free_content(&file);exit(1);}
# define STARTEND {start = find_start(room_head);end = start;}
# define QQ {temp->room->weight = queue->room->weight + 1;}
# define QADD {queue_add(queue, temp->room);QQ}
# define MSG1 "ERROR : No start OR end room has been found"
# define MSG2 "ERROR : Undefined. (This may mean several things. "
# define MSG22 "Please consult the map guidelines.)"
# define READMAPVARS {count = 0;rooms = NULL;file = NULL;}
# define LINEOPS {check_line(line, &file);free(line);}
# define START_NODE {node->start = 1;node->end = 0;}
# define END_NODE {node->start = 0;node->end = 1;}
# define NODE {node->start = 0;node->end = 0;}

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
	PATH_ERROR,
	UNDEFINED,
	INT_MAX
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
	int					ant_count;
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

typedef struct			s_ant
{
	int					ant_num;
	char				*curr_path;
	t_path				*path;
}						t_ant;

/*
**	Reading & Basic Error Checks of Input
*/

t_rooms					*read_map(void);
void					check_line(char *line, t_content **file);
int						word_manager(char *line, int words);
int						word_count(char *str);
int						is_command(char *line);
int						bad_command(char *line);
int						is_comment(char *line);
int						is_room(char *line);
int						is_link(char *line);
int						is_ant(char *line);
int						all_digits_check(char *str);
int						dash_check(char *str);
char					*whitespace_remover(char *str, int type,
												t_content **file);

/*
**	Erroring
*/

void					free_rooms_error(t_rooms **node, int msg);
void					free_content_error(t_content **node, int msg);
void					error_out(int code);

/*
**	Advanced Error Checking
*/

int						advanced_check_and_fill(t_content **file,
												t_rooms **head);
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
void					generate_moves(t_path *path, t_rooms **room_head);
void					attack(t_ant **ants, t_rooms **rooms, int total);
void					display_ants(t_ant *ant, t_rooms **rooms);
void					execute(t_ant *curr_ant);

/*
**	t_path functions
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
void					free_links(t_links **links);
void					free_rooms(t_rooms **head);
void					set_ants(t_rooms **rooms, t_content **content);

#endif
