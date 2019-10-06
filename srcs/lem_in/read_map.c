/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:15:37 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/19 11:05:29 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int			word_manager(char *line, int words)
{
	if (words == 1)
	{
		if (is_command(line) == 1)
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

void		check_line(char *line, t_content **file)
{
	int	words;
	int	status;

	if (is_comment(line))
		return ;
	words = word_count(line);
	if (words == 0)
		free_content_error(file, EMPTY_LINE);
	status = word_manager(line, words);
	if (status == 0)
		free_content_error(file, BAD_INPUT);
	line = whitespace_remover(line, status, file);
	ft_putendl_col_fd(YELLOW, line, 1);					//
	(*file) = init_content(file, line);
	free(line);
}

t_rooms		*read_map(void)
{
	char		*line;
	t_content	*file;
	t_rooms		*rooms;
	int			count;

	count = 0;
	rooms = NULL;
	file = NULL;
	while (get_next_line(0, &line))
	{
		check_line(line, &file);
		free(line);
		count++;
	}
	if (count > 1)
	{
		if (advanced_check_and_fill(&file, &rooms) == 0)
		{
			if (rooms)
				free_rooms(&rooms);
			free_content_error(&file, 200);
		}
		print_content(&file);
	}
	else
		free_content_error(&file, BAD_INPUT);
	free_content(&file);
	return (rooms);
}
