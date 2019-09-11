/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:58:28 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/06 15:39:13 by jhansen          ###   ########.fr       */
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
