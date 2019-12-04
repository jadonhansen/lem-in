/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:27:07 by jhansen           #+#    #+#             */
/*   Updated: 2019/12/04 13:42:46 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		attack(t_ant **ants, t_rooms **rooms, int total)
{
	t_rooms	*end;
	int		i;

	i = 0;
	end = *rooms;
	while (end && end->end != 1)
		end = end->next;
	while (end->ant_count != total)
	{
		i = 0;
		while (i < total)
			display_ants(ants[i++], rooms);
		ft_putendl("");
	}
}

void		generate_moves(t_path *path, t_rooms **room_head)
{
	t_ant	**ants;
	t_rooms	*temp;
	int		i;
	int		total;

	temp = find_start(room_head);
	total = temp->ant_count;
	i = 1;
	if ((ants = (t_ant **)malloc(sizeof(t_ant *) * total))) {
		while (i <= total) 
		{
			ants[i - 1] = (t_ant *)malloc(sizeof(t_ant));
			ants[i - 1]->ant_num = i;
			ants[i - 1]->curr_path = path->name;
			ants[i - 1]->path = path;
			i++;
		}
		attack(ants, room_head, total);
		i = 0;
		while (i < total)
			free(ants[i++]);
		free(ants);
	}
}

t_path		*generate_path(t_rooms *start)
{
	t_path	*path;
	t_rooms	*room;
	t_links	*temp;

	room = start;
	path = NULL;
	while (room && room->end != 1)
		room = room->next;
	add_path(&path, room->name);
	while (room && room->start != 1)
	{
		temp = room->links;
		while (temp)
		{
			if (room->weight == (temp->room->weight + 1))
			{
				add_path(&path, temp->room->name);
				room = temp->room;
			}
			temp = temp->next;
		}
	}
	path_correction(&path);
	return (path);
}

int			path_find(t_rooms **room_head)
{
	t_rooms	*start;
	t_rooms	*end;
	t_queue	*queue;
	t_links	*temp;

	start = find_start(room_head);
	end = start;
	while (end->end != 1)
		end = end->next;
	queue = queue_node(start);
	start->weight = 1;
	while (queue && end->weight == 0)
	{
		temp = queue->room->links;
		while (temp)
		{
			if (temp->room->weight == 0)
			{
				queue_add(queue, temp->room);
				temp->room->weight = queue->room->weight + 1;
			}
			temp = temp->next;
		}
		queue_remove(&queue);
	}
	free_queue(&queue);
	if (!(end->weight))
		return (0);
	return (1);
}
