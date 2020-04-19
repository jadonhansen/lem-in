/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <cdiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:19:08 by cdiogo            #+#    #+#             */
/*   Updated: 2020/01/16 15:14:30 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** Manages all algo operations once validation is complete
*/

void	bigboy_algo(t_rooms **room_head)
{
	t_path	*path;

	if (path_find(room_head))
	{
		path = generate_path(find_start(room_head));
		generate_moves(path, room_head);
	}
	else
		free_rooms_error(room_head, PATH_ERROR);
	free_path(&path);
}

int		main(void)
{
	t_rooms	*rooms;

	rooms = read_map();
	bigboy_algo(&rooms);
	free_rooms(&rooms);
	return (0);
}
