/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:45:52 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/03 17:21:02 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		check_for_ant(t_content **head)
{
	t_content	*temp;
	int			num;

	if (*head)
	{
		temp = *head;
		if (is_ant(temp->content))
		{
			num= ft_atol(temp->content);
			if (num > MAX || num < MIN)
				return (0);
			return (1);
		}
	}
	return (0);
}

int		advanced_check_and_fill(t_content **file, t_rooms **head)
{
	if (!(*file))
		return (0);
	if (check_for_ant(file))
	{
		return (1);
		//duplicate room names
		//links to a valid room(something that exists)
		//check that the links of the rooms link up correctly. HOW?
	}
	return (0);
}