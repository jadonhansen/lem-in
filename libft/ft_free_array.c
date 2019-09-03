/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:58:28 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/19 15:01:20 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Frees the malloc'd elements of an array before freeing the pointer to
** the array.
*/

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
