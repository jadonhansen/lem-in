/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:19:08 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/03 16:59:41 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		main(int ac, char **av)
{
	// lots of error checking
	// input, room validation (Names won't start with '#' or 'L'), link validation
	// ignore # comments, accept ## commands (valid ones, so 'start' and 'end')
	// need to have a func that checks if a room is occupied. --Add a bool to struct?
	// must display input, empty line, then moves
	// ^^ Input = num ants, ##commands, rooms, links

	t_rooms	*rooms;

	av = av + 1;
	rooms = read_map(); 		//checks each line of text that it is valid. Shoves input into corresponding list members if it is valid.
	ft_putendl("");
	//while(1); 		//tests for leaks
	return (0);
}
