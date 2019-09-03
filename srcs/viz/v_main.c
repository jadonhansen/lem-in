/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 09:10:12 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/03 16:47:06 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"

int		main(void)
{
	t_viz	*visualizer;
	t_rooms	*info;
	t_moves	*moves; //include moves within the main lem_in struct instead?
	//TODO
	//read in from GNL (read until empty line, then set a bool to false to change the struct being written to?)
	info = NULL;
	// info = init_rooms(&info, line);
	info = read_info(&info);
	//init the viz struct
	visualizer = init_viz();
	//allocate/populate to the viz struct
	populate_viz(visualizer);
	//draw links
	// draw_links();
	//draw rooms
	// draw_rooms();
	//draw ants
	// draw_ants();
	//event loop (space to move through the turns)
	event_loop(visualizer, info, moves); //handle drawing things in the event loop?
	//free & close upon completion
	viz_free(&visualizer);
	return (0);
}
