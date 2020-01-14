/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_check_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:09:04 by jhansen           #+#    #+#             */
/*   Updated: 2020/01/14 12:32:39 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** Checks for duplicate room names and co-ordinates
*/

int			duplicate_rooms(t_rooms **rooms)
{
	t_rooms	*temp;
	t_rooms	*current;

	temp = *rooms;
	current = NULL;
	while (temp->next != NULL)
	{
		current = temp->next;
		while (current != NULL)
		{
			if (ft_strequ(temp->name, current->name))
			{
				error_out(DUP_ROOM);
				return (0);
			}
			if ((temp->x == current->x) && (temp->y == current->y))
			{
				error_out(DUP_XY);
				return (0);
			}
			current = current->next;
		}
		temp = temp->next;
	}
	return (1);
}

/*
** Checks that there are no duplicate links OR REVERSE duplicate links
** (e.g. 1-2 and 2-1)
*/

int			double_check(char *current, char *temp)
{
	char	**one;
	char	**two;
	int		flag;

	flag = 0;
	one = ft_strsplit(current, '-');
	two = ft_strsplit(temp, '-');
	if (((ft_strequ(one[0], two[0]) && ft_strequ(one[1], two[1]))
		|| (ft_strequ(one[0], two[1]) && ft_strequ(one[1], two[0]))))
		flag = 1;
	free(one[0]);
	free(one[1]);
	free(two[0]);
	free(two[1]);
	free(one);
	free(two);
	if (flag == 1)
		return (0);
	return (1);
}

/*
** Checks that there are no duplicate links
*/

int			duplicate_link(t_content **file)
{
	t_content	*temp;
	t_content	*current;

	temp = *file;
	current = NULL;
	while (temp != NULL)
	{
		if ((word_count(temp->content) == 1) && is_link(temp->content))
		{
			if (temp->next != NULL)
				current = temp->next;
			while (current != NULL)
			{
				if ((word_count(current->content) == 1)
						&& is_link(current->content))
				{
					if (double_check(temp->content, current->content) == 0)
						ERRDUPLINK;
				}
				current = current->next;
			}
		}
		temp = temp->next;
	}
	return (1);
}

/*
** Checks that the room on each side the '-' in the link is an existing room
*/

int			cross_check(t_rooms **head, char *s)
{
	t_rooms	*temp;
	char	**arr;
	int		flag;

	temp = *head;
	arr = ft_strsplit(s, '-');
	flag = 0;
	while (temp != NULL)
	{
		if (ft_strequ(arr[0], temp->name))
			flag++;
		if (ft_strequ(arr[1], temp->name))
			flag++;
		temp = temp->next;
	}
	ft_free_array(arr);
	if (flag == 2)
		return (1);
	return (0);
}

/*
** Checks that a link refers to an actual room
*/

int			existing_room(t_content **file, t_rooms **head)
{
	t_content	*temp;

	if (*file && *head)
		temp = *file;
	else
		return (0);
	while (temp != NULL)
	{
		if ((word_count(temp->content) == 1) && is_link(temp->content))
		{
			if (cross_check(head, temp->content) == 0)
			{
				error_out(NON_EXISTING_ROOM);
				return (0);
			}
		}
		temp = temp->next;
	}
	return (1);
}
