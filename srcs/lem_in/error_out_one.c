/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_out_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:43:46 by cdiogo            #+#    #+#             */
/*   Updated: 2019/10/04 22:50:54 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	error_out(int code)
{
	if (code == NO_ANTS)
		ft_putendl_col_fd(RED, "ERROR : No ants provided", 2);
	if (code == DUP_ROOM)
		ft_putendl_col_fd(RED, "ERROR : Duplicate room names", 2);
	if (code == DUP_XY)
		ft_putendl_col_fd(RED, "ERROR : Duplicate x and y coordinates", 2);
	if (code == DUP_LINK)
		ft_putendl_col_fd(RED, "ERROR : Duplicate links", 2);
	if (code == NO_START_OR_END)
		ft_putendl_col_fd(RED, "ERROR : No Start OR End room has been found", 2);
	if (code == BAD_INPUT)
		ft_putendl_col_fd(RED, "ERROR : Bad Input", 2);
	if (code == BAD_COMMAND)
		ft_putendl_col_fd(RED, "ERROR : Bad command", 2);
	if (code == EMPTY_LINE)
		ft_putendl_col_fd(RED, "ERROR : Empty line", 2);
	if (code == ERROR)
		ft_putendl_col_fd(RED, "ERROR : Advanced check ERROR", 2);
	if (code == NON_EXISTING_LIST)
		ft_putendl_col_fd(RED, "ERROR : Non-existing list", 2);
	if (code == NON_EXISTING_ROOM)
		ft_putendl_col_fd(RED, "ERROR : Non-existing room found", 2);
	if (code == TOO_MANY_ANTS)
		ft_putendl_col_fd(RED, "ERROR : Multiple ant lines found", 2);
	if (code == NO_LINK)
		ft_putendl_col_fd(RED, "ERROR : No links found", 2);
}

void	free_content_error(t_content **node, int msg)
{
	free_content(node);
	error_out(msg);
	exit(1);
}

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