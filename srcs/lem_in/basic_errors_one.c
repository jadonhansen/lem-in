/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_errors_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:17:39 by cdiogo            #+#    #+#             */
/*   Updated: 2020/01/14 12:33:01 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** Checks if the line inputted is of command type
*/

int		is_command(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '#' && line[i + 1] == '#')
	{
		if (ft_str_contain("##start", &line[i])
			|| ft_str_contain("##end", &line[i]))
			return (1);
	}
	return (0);
}

/*
** Checks if the line inputted is of comment type
*/

int		is_comment(char *line)
{
	int	i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (line[i] == '#' && line[i + 1] != '#')
		return (1);
	return (0);
}

/*
** Checks if the line inputted is of link type
*/

int		is_link(char *line)
{
	int	i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (dash_check(&line[i]) && line[i] != 'L')
		return (1);
	return (0);
}

/*
** Checks if the line inputted is of ant type
*/

int		is_ant(char *line)
{
	int	i;

	i = 0;
	if (line)
	{
		while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
			i++;
		while (line[i] != '\0' && line[i] != ' ' && line[i] != '\t')
		{
			if (line[i] >= '0' && line[i] <= '9' && line[i] != '\0')
				i++;
			else
				return (0);
		}
	}
	return (1);
}

/*
** Checks if the line inputted is of room type
*/

int		is_room(char *line)
{
	int	i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (line[i] != 'L')
	{
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		{
			if (line[i] == '-')
				return (0);
			i++;
		}
		while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
			i++;
		if (all_digits_check(&line[i]))
			return (1);
	}
	return (0);
}
