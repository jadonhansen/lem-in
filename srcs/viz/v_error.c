/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <cdiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:52:14 by cdiogo            #+#    #+#             */
/*   Updated: 2020/01/06 14:18:44 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"

/*
** Frees everything in the viz struct, before freeing the struct itself
*/

void	viz_free(t_viz **viz)
{
	if (viz && *viz)
	{
		SDL_DestroyTexture((*viz)->ant);
		SDL_DestroyTexture((*viz)->room);
		SDL_DestroyTexture((*viz)->bg);
		SDL_DestroyRenderer((*viz)->rend);
		SDL_DestroyWindow((*viz)->window);
		SDL_Quit();
		free(*viz);
		(*viz) = NULL;
	}
}

/*
** Handles freeing the viz struct and printing an error message if appropriate
*/

void	viz_error_free(t_viz *viz, const char *error)
{
	if (viz)
		viz_free(&viz);
	ft_putendl_col_fd(RED, (char*)error, 2);
	exit(1);
}
