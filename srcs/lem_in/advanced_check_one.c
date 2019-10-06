/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_check_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:45:52 by jhansen           #+#    #+#             */
/*   Updated: 2019/10/06 12:25:59 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

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
	{
		ft_putendl_col_fd(RED, "Done end start room check", 1);		//
		return (1);
	}
	error_out(NO_START_OR_END);
	return (0);
}

int		check_for_ant(t_content **head)
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
				return (0);
			while (node->next != NULL)
			{
				node = node->next;
				if (word_count(node->content) == 1 && is_ant(node->content))
				{
					error_out(TOO_MANY_ANTS);
					return (0);
				}
			}
			return (1);
		}
	}
	error_out(NO_ANTS);
	return (0);
}

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

int		advanced_check_and_fill(t_content **file, t_rooms **head)
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
		ft_putendl_col_fd(RED, "Filled room struct", 1);		//
		if (head && duplicate_rooms(head) && is_endstart(head) && duplicate_link(file))
		{
			ft_putendl_col_fd(RED, "DONE MAIN CHECKS", 1);		//
			if (*head && existing_room(file, head))
			{
				init_links(file, head);
				return (1);
			}
		}
	}
	return (0);
}