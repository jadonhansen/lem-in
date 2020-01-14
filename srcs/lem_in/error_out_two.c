/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_out_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:08:43 by jhansen           #+#    #+#             */
/*   Updated: 2020/01/14 11:44:56 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** An error case function. Free's room struct and quits
*/

void	free_rooms_error(t_rooms **node, int msg)
{
	free_rooms(node);
	error_out(msg);
	exit(1);
}

/*
** Free's link struct
*/

void	free_links(t_links **links)
{
	t_links	*temp;
	t_links	*next;

	next = NULL;
	temp = *links;
	if (temp)
	{
		while (temp != NULL)
		{
			next = temp->next;
			free(temp->name);
			free(temp);
			temp = next;
		}
		*links = NULL;
	}
}

/*
** Free's room struct
*/

void	free_rooms(t_rooms **head)
{
	t_rooms	*temp;
	t_rooms	*next;

	next = NULL;
	if (*head != NULL)
	{
		temp = *head;
		while (temp)
		{
			next = temp->next;
			if (temp->links)
				free_links(&temp->links);
			free(temp->name);
			free(temp);
			temp = next;
		}
		*head = NULL;
	}
}
