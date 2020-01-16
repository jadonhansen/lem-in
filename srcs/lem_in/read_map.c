/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:15:37 by cdiogo            #+#    #+#             */
/*   Updated: 2020/01/16 14:18:08 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** Manual checks to see the type of line read from the file.
** If an existing type is found the return is > 0
*/

int			word_manager(char *line, int words)
{
	if (words == 1)
	{
		if (is_command(line))
			return (1);
		else if (is_ant(line))
			return (1);
		else if (is_link(line))
			return (1);
	}
	else if (words == 3)
	{
		if (is_room(line))
			return (3);
	}
	return (0);
}

/*
** Validates each line that is read from the file.
** If succesful all unnecesary whitespace is removed and then
** the line is added to the struct
*/

void		check_line(char *line, t_content **file)
{
	int		words;
	int		status;
	char	*no_white;

	if (is_comment(line) || bad_command(line))
	{
		(*file) = init_content(file, line);
		return ;
	}
	words = word_count(line);
	if (words == 0)
		free_content_error(file, EMPTY_LINE);
	status = word_manager(line, words);
	if (status == 0)
		free_content_error(file, BAD_INPUT);
	no_white = whitespace_remover(line, status, file);
	(*file) = init_content(file, no_white);
	free(no_white);
}

/*
** Reads all line from the file and does real time validation.
** If successful, memory is freed and the room struct is returned.
*/

t_rooms		*read_map(void)
{
	char		*line;
	t_content	*file;
	t_rooms		*rooms;
	int			count;

	READMAPVARS;
	while (get_next_line(0, &line))
	{
		LINEOPS;
		count++;
	}
	if (count > 1)
	{
		if (advanced_check_and_fill(&file, &rooms) == 0)
		{
			if (rooms)
				free_rooms(&rooms);
			FREEEXIT;
		}
		print_content(&file);
	}
	else
		free_content_error(&file, BAD_INPUT);
	free_content(&file);
	return (rooms);
}
