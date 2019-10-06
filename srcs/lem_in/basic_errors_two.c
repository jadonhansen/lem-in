/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_errors_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 08:37:21 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/18 13:01:16 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		word_count(char *str)
{
	int	i;
	int	count;

	count = 0;
	if (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
		{
			while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
				i++;
			if (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
				count++;
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
				i++;
		}
	}
	return (count);
}

int		dash_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '-')
	{
		if (((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= '0' && str[i] <= '9')))
			i++;
		else
			return (0);
	}
	if (str[i] == '-' && str[i + 1] != 'L' && str[i + 1] != '\0')
	{
		i++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		{
			if (((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
					|| (str[i] >= '0' && str[i] <= '9')))
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

int		all_digits_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
