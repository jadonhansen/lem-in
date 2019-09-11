/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_free_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:33:39 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/11 13:55:59 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		arr_len(char **s)
{
	int	i = 0;

	while (s[i] != NULL)
		i++;
	return (i);
}

void	ft_free_array(char **arr)
{
	int	i = 0;
	int len = arr_len(arr);

	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_putstr(char *s)
{
	int	i = 0;

	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		main(void)
{
	char **arr;

	arr = (char **)malloc(sizeof(char *) * 4);
	arr[0] = (char *)malloc(sizeof(char) * 6);
	arr[1] = (char *)malloc(sizeof(char) * 6);
	arr[2] = (char *)malloc(sizeof(char) * 6);
	arr[3] = NULL;
	arr[0] = "Jadon\0";
	arr[1] = "Jadon\0";
	arr[2] = "Jadon\0";
	ft_putstr(arr[0]);
	ft_putstr(arr[1]);
	ft_putstr(arr[2]);
	ft_free_array(arr);
	while (1);
	return (0);
}