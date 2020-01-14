/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_errors_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 08:37:21 by cdiogo            #+#    #+#             */
/*   Updated: 2020/01/14 13:39:55 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** If a command type line is found it is checked if the command
** is a valid command
*/

int		bad_command(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '#' && line[i + 1] == '#')
	{
		if (ft_str_contain("##start", &line[i])
			|| ft_str_contain("##end", &line[i]))
			return (0);
		else
			return (1);
	}
	return (0);
}

/*
** Returns the word count of a line
*/

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

/*
** A dash check is required if a link type line is found.
** (A link must have one dash between two rooms names)
*/

int		dash_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '-')
	{
		if (((str[i] >= 'A' && str[i] <= 'Z') ||
		(str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
			i++;
		else
			return (0);
	}
	if (str[i] == '-' && str[i + 1] != 'L' && str[i + 1] != '\0')
	{
		i++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		{
			if (((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a'
			&& str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

/*
** Checks that all characters in a line is as of numeric character
*/

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
