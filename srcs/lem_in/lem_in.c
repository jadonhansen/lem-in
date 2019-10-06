/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:19:08 by cdiogo            #+#    #+#             */
/*   Updated: 2019/10/06 13:50:46 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	bigboy_algo(t_rooms **room_head)
{
	// need to have a func that checks if a room is occupied. --Add a bool to struct?

	t_path	*path;

	if (path_find(room_head))
	{
		path = generate_path(find_start(room_head));
		//generate_moves();
	}
	else
		free_rooms_error(room_head, PATH_ERROR);
	print_path(&path);		//debug
	free_path(&path);
}

int		main(void)
{
	// must display input, empty line, then moves

	t_rooms	*rooms;

	rooms = read_map();
	bigboy_algo(&rooms);
	print_rooms(&rooms);			//debug
	free_rooms(&rooms);
	//while(1);					//tests for leaks at the end
	return (0);
}
