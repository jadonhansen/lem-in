/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_ops_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:42:14 by jhansen           #+#    #+#             */
/*   Updated: 2020/01/16 14:16:47 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** Creates a copy of the line given without any whitespace around it
*/

char	*whitespace_rooms(char *str)
{
	char	*line;
	int		i;
	int		j;

	j = -1;
	i = 0;
	line = (char *)malloc(sizeof(char) * 6);
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
			i++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
			line[++j] = str[i++];
		line[++j] = ' ';
	}
	line[j] = '\0';
	return (line);
}

/*
** Creates a copy of the line given without any whitespace around
** it BUT with any length of string given
*/

char	*whitespace_else(char *str)
{
	char	*line;
	int		len;
	int		i;
	int		j;
	int		k;

	len = 0;
	i = 0;
	j = -1;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	k = i;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
	{
		len++;
		i++;
	}
	line = (char *)malloc(sizeof(char) * len);
	while (str[k] != '\0' && str[k] != ' ' && str[k] != '\t')
		line[++j] = str[k++];
	line[++j] = '\0';
	return (line);
}

/*
** Manages removal of whitespace
*/

char	*whitespace_remover(char *str, int type, t_content **file)
{
	char	*line;

	if (str)
	{
		if (type == 3)
			line = whitespace_rooms(str);
		else
			line = whitespace_else(str);
	}
	else
		free_content_error(file, NON_EXISTING_LIST);
	return (line);
}
