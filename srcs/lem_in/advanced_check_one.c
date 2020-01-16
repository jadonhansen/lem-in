/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_check_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:45:52 by jhansen           #+#    #+#             */
/*   Updated: 2020/01/16 14:17:55 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** Checks that there is a start and end room which is mandatory
*/

int			is_endstart(t_rooms **head)
{
	t_rooms	*temp;
	int		flag;

	temp = *head;
	flag = 0;
	while (temp != NULL)
	{
		if (temp->start == 1)
			flag++;
		else if (temp->end == 1)
			flag++;
		temp = temp->next;
	}
	if (flag == 2)
		return (1);
	error_out(NO_START_OR_END);
	return (0);
}

/*
** Checks that the input has given an ant count as the first line
*/

int			check_for_ant(t_content **head)
{
	t_content	*temp;
	t_content	*node;
	long		num;

	if (*head)
	{
		temp = *head;
		node = *head;
		if (is_ant(temp->content))
		{
			num = ft_atol(temp->content);
			if (num > MAX || num < MIN)
				ANT_MAX;
			while (node->next != NULL)
			{
				node = node->next;
				if (word_count(node->content) == 1 && is_ant(node->content))
					ERR2ANT;
			}
			return (1);
		}
	}
	ERRNOANT;
}

/*
** Checks that there is at least one link found in the file
*/

int			check_for_link(t_content **file)
{
	t_content	*temp;
	int			count;

	count = 0;
	if (*file)
	{
		temp = *file;
		while (temp != NULL)
		{
			if (word_count(temp->content) == 1 && is_link(temp->content))
				count++;
			temp = temp->next;
		}
		if (count >= 1)
			return (1);
		error_out(NO_LINK);
	}
	return (0);
}

/*
** Fills room struct with rooms found in the content struct
*/

t_rooms		*filler(t_content **file, t_rooms **head)
{
	t_content	*temp;

	temp = *file;
	while (temp != NULL)
	{
		if (word_count(temp->content) == 3)
			*head = init_rooms(head, temp->content, 0);
		else if (ft_strequ("##start", temp->content))
		{
			temp = temp->next;
			if (word_count(temp->content) == 3)
				*head = init_rooms(head, temp->content, 1);
		}
		else if (ft_strequ("##end", temp->content))
		{
			temp = temp->next;
			if (word_count(temp->content) == 3)
				*head = init_rooms(head, temp->content, 2);
		}
		temp = temp->next;
	}
	return (*head);
}

/*
** Manages advanced checks and returns
*/

int			advanced_check_and_fill(t_content **file, t_rooms **head)
{
	t_content	*temp;

	if (!(*file))
	{
		error_out(NON_EXISTING_LIST);
		return (0);
	}
	temp = *file;
	if (check_for_ant(file) && check_for_link(file))
	{
		*head = filler(file, head);
		if (head && duplicate_rooms(head) && is_endstart(head)
				&& duplicate_link(file))
		{
			if (*head && existing_room(file, head))
			{
				init_links(file, head);
				set_ants(head, file);
				return (1);
			}
		}
	}
	return (0);
}
