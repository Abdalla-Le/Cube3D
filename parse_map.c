/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:48:28 by ancarlos          #+#    #+#             */
/*   Updated: 2026/01/13 14:21:34 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void fill_list(t_gnl **lst, char *line)
{
	static int	i = 0;

	ft_lstadd_back(lst,ft_lstnew(ft_strdup(line), i));
	i++;
}

char	**fill_matrix(t_gnl **lst)
{
	t_gnl	*temp;
	int		i;
	char **grid;
	
	i = 0;
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	grid = malloc(sizeof(char *) * (temp->index + 2));
	if(!grid)
		return (NULL);
	temp = *lst;
	while (temp != NULL)
	{
		grid[i] = ft_strdup(temp->line);
		temp = temp->next;
		i++;
	}
	grid[i] = NULL;
	return (grid);
}

int parse_map(int fd, t_map *file, char *line, t_gnl **lst)
{
	(void)fd;
	(void)file;
	fill_list(lst, line);
	return (1);
}