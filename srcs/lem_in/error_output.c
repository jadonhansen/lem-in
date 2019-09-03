/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:43:46 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/03 15:33:32 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	error_out(int code)
{
	if (code == NO_ANTS)
		ft_putendl_col_fd(RED, "ERROR : No ants provided", 2);
	if (code == DUP_ROOM)
		ft_putendl_col_fd(RED, "ERROR : Duplicate Room names", 2);
	if (code == DUP_LINK)
		ft_putendl_col_fd(RED, "ERROR : Duplicate Links", 2);
	if (code == NO_START)
		ft_putendl_col_fd(RED, "ERROR : No Start Room found", 2);
	if (code == NO_END)
		ft_putendl_col_fd(RED, "ERROR : No End Room found", 2);
	if (code == BAD_INPUT)
		ft_putendl_col_fd(WHITE, "usage: ./lem-in < [path/to/map]", 2);
		// ft_putendl_col_fd(RED, "ERROR : Bad Input", 2);
	if (code == BAD_COMMAND)
		ft_putendl_col_fd(RED, "ERROR : Bad Command", 2);
	if (code == EMPTY_LINE)
		ft_putendl_col_fd(RED, "ERROR : Empty Line", 2);
	if (code == ERROR)
		ft_putendl_col_fd(RED, "ERROR : Advanced Check ERROR", 2);
	if (code == NON_EXISTING_LIST)
		ft_putendl_col_fd(RED, "ERROR : Non-existing list", 2);
	exit(1);
}

void	free_content_error(t_content **node, int msg)
{
	free_content(node);
	error_out(msg);
}

void				free_content(t_content **head)
{
	t_content	*current;
	t_content	*next;

	if (*head)
	{
		current = *head;
		while (current)
		{
			next = current->next;
			free(current->content);
			free(current);
			current = next;
		}
		*head = NULL;
	}
}

void	free_rooms_error(t_rooms **node, int msg)
{
	free_rooms(node);
	error_out(msg);
}

void				free_rooms(t_rooms **head)
{
	t_rooms	*current;
	t_rooms	*next;

	if (*head != NULL)
	{
		current = *head;
		while (current)
		{
			ft_putendl("While!");
			next = current->next;
			//free(current->name);		//only free laters
			free(current);
			current = next;
		}
		*head = NULL;
	}
}
