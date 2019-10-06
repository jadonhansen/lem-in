/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:25:16 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/20 10:41:50 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <viz.h>

/*
** Reads in piped input, assigns to struct for later use in the visualizer
*/

int		v_populate_map(char **mappy, t_room **room, t_moves **moves)
{
	char	*file;

	get_next_line(0, &file);
	validate(file, mappy, 0, room);
	free(file);
	while (get_next_line(0, &file))
	{
		if (file[0] == '\0')
		{
			(file) ? free(file) : NULL;
			break ;
		}
		validate(file, mappy, 1, room);
		(file) ? free(file) : NULL;
	}
	validate(NULL, NULL, 42, room);
	while (get_next_line(0, &file))
	{
		(*moves) = init_moves(moves, file);
		(file) ? free(file) : NULL;
	}
	return (1);
}

/*
** Determines length of the ID of the ant
*/

int		id_length(char *line)
{
	int i;

	i = 0;
	while (line[i] != '-')
		i++;
	return (i);
}

/*
** Updates the current and previous rooms for the ant `ant_id`
*/

void	update_ant(t_ants **ants, char *ant_id, char *room_name, t_room **info)
{
	t_ants	*tmp_a;
	t_room	*tmp_r;

	tmp_a = *ants;
	tmp_r = *info;
	while (!ft_strequ(tmp_a->id, ant_id))
		tmp_a = tmp_a->next;
	while (!ft_strequ(tmp_r->name, room_name))
		tmp_r = tmp_r->next;
	tmp_a->previous = tmp_a->current;
	tmp_a->current = tmp_r;
}
