/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_traversal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:12:49 by bmarks            #+#    #+#             */
/*   Updated: 2019/09/20 12:22:27 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in2.h>

static void	march(t_ant **ants, t_room **rooms)
{
	int		i;
	t_room	*end;
	int		num;

	num = (*rooms)->ant_count;
	end = *rooms;
	while (end && end->type != 2)
		end = end->next;
	while (end->ant_count != num)
	{
		i = 0;
		while (i < num)
			disp_ants(ants[i++], rooms);
		ft_putendl("");
	}
}

void		traversal(t_path *path, t_room **rooms)
{
	t_ant		**ants;
	int			i;
	const int	num = (*rooms)->ant_count;

	i = 1;
	if (!(ants = (t_ant **)malloc(sizeof(t_ant *) * num)))
		MAL_ERROR;
	while (i <= num)
	{
		if (!(ants[i - 1] = (t_ant *)malloc(sizeof(t_ant))))
			MAL_ERROR;
		ants[i - 1]->ant_num = i;
		ants[i - 1]->curr_room = path->room_name;
		ants[i - 1]->path = path;
		i++;
	}
	march(ants, rooms);
	i = 0;
	while (i < num)
		free(ants[i++]);
	free(ants);
}

t_room		*find_room(t_room *room, char *name)
{
	while (room)
	{
		if (ft_strequ(room->name, name))
			return (room);
		room = room->next;
	}
	return (room);
}
