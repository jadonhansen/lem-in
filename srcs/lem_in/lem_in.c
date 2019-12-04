/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:19:08 by cdiogo            #+#    #+#             */
/*   Updated: 2019/12/04 12:09:20 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

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
	// print_path(&path);		// for debugging
	free_path(&path);
}

int		main(void)
{
	t_rooms	*rooms;

	rooms = read_map();
	bigboy_algo(&rooms);
	// print_rooms(&rooms);			// for debugging
	free_rooms(&rooms);
	// while(1);					//tests for leaks at the end
	return (0);
}
