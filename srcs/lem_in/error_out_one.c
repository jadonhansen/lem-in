/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_out_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:43:46 by cdiogo            #+#    #+#             */
/*   Updated: 2020/01/16 14:53:46 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** Error message function
*/

void	err(int code)
{
	if (code == NO_LINK)
		ft_putendl_col_fd(RED, "ERROR : No links found", 2);
	else if (code == NO_START_OR_END)
		ft_putendl_col_fd(RED, "ERROR : No start or end room found", 2);
	else if (code == INT_MAX)
		ft_putendl_col_fd(RED, "ERROR : Your ant count reached int max", 2);
	else if (code == NON_EXISTING_LIST)
		ft_putendl_col_fd(RED, "ERROR : Non-existing list", 2);
	else if (code == PATH_ERROR)
		ft_putendl_col_fd(RED, "ERROR : No path found", 2);
}

void	error_out(int code)
{
	if (code == NO_ANTS)
		ft_putendl_col_fd(RED, "ERROR : No ants provided", 2);
	else if (code == DUP_ROOM)
		ft_putendl_col_fd(RED, "ERROR : Duplicate room names", 2);
	else if (code == DUP_XY)
		ft_putendl_col_fd(RED, "ERROR : Duplicate x and y coordinates", 2);
	else if (code == DUP_LINK)
		ft_putendl_col_fd(RED, "ERROR : Duplicate links", 2);
	else if (code == BAD_INPUT)
		ft_putendl_col_fd(RED, "ERROR : Bad input", 2);
	else if (code == BAD_COMMAND)
		ft_putendl_col_fd(RED, "ERROR : Bad command", 2);
	else if (code == EMPTY_LINE)
		ft_putendl_col_fd(RED, "ERROR : Empty line", 2);
	else if (code == ERROR)
		ft_putendl_col_fd(RED, "ERROR : Advanced check ERROR", 2);
	else if (code == NON_EXISTING_ROOM)
		ft_putendl_col_fd(RED, "ERROR : Non-existing room found", 2);
	else if (code == TOO_MANY_ANTS)
		ft_putendl_col_fd(RED, "ERROR : Multiple ant lines found", 2);
	else
		err(code);
}

/*
** Error function
*/

void	free_content_error(t_content **node, int msg)
{
	free_content(node);
	error_out(msg);
	exit(1);
}

/*
** Free's content struct
*/

void	free_content(t_content **head)
{
	t_content	*current;
	t_content	*next;

	current = NULL;
	next = NULL;
	if (*head)
	{
		current = *head;
		while (current)
		{
			next = current->next;
			if (current->content)
				free(current->content);
			free(current);
			current = next;
		}
		*head = NULL;
	}
}
