/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:48:28 by ancarlos          #+#    #+#             */
/*   Updated: 2026/01/08 20:12:07 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void fill_list(t_gnl **lst, char *line)
{
	static int	i;

	i = 1;
	ft_lstadd_back(lst,ft_lstnew(ft_strdup(line), i));
	i++;
}

void	fill_matrix(char **grid, t_gnl **lst)
{
	t_gnl	*temp;
	
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	grid = malloc(temp->index);
	temp = *lst;
	while (temp != NULL)
	{
		
	}
	
}

int parse_map(int fd, t_map *file, char *line, t_gnl **lst)
{
	(void)fd;
	(void)file;
	fill_list(lst, line);
	fill_matrix(file->grid, line);
	return (1);
}