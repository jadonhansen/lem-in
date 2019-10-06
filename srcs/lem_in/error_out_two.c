/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_out_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:08:43 by jhansen           #+#    #+#             */
/*   Updated: 2019/10/04 23:48:26 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	free_rooms_error(t_rooms **node, int msg)
{
	free_rooms(node);
	error_out(msg);
	exit(1);
}

void                free_links(t_links **links)
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

void				free_rooms(t_rooms **head)
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
