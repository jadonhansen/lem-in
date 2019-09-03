/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 08:40:20 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/03 17:19:58 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# define MAX 2147483647
# define MIN -2147483648
// DEBUGGING VVV
# include <stdio.h>
// DEBUGGING ^^^

/*
** Macros
*/

enum					e_error_codes
{
	NO_ANTS = 1,
	DUP_ROOM,
	DUP_LINK,
	NO_START,
	NO_END,
	NO_X,
	NO_Y,
	BAD_INPUT,
	BAD_COMMAND,
	EMPTY_LINE,
	ERROR,
	NON_EXISTING_LIST
};

typedef struct			s_content
{
	char				*content;
	struct s_content	*next;
}						t_content;

typedef struct			s_rooms
{
	char				*name;
	int					x;
	int					y;
	int					start;
	int					end;
	struct s_rooms		*next;
	//struct to hold links
	//struct to hold moves if needed
}						t_rooms;

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
**	Erroring and Freeing
*/

void					free_rooms(t_rooms **head);
void					free_rooms_error(t_rooms **node, int msg);
void					free_content_error(t_content **node, int msg);
void					error_out(int code);

/*
**	Advanced Error Checking
*/

int						advanced_check_and_fill(t_content **file, t_rooms **head);
int						check_for_ant(t_content **head);
int						valid_link(char *line);
int						valid_room(char *line);

/*
**  t_content funcs
*/

t_content				*init_content(t_content **file, char *line);
void					print_content(t_content **head);
void					free_content(t_content **head);

/*
**	t_rooms funcs
*/

t_rooms					*init_rooms(t_rooms **file, char *line);

#endif
