/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:06:09 by ancarlos          #+#    #+#             */
/*   Updated: 2026/01/20 18:15:57 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void fill_list(t_gnl **lst, char *line)
{
	static int	i = 0;

	ft_lstadd_back(lst,ft_lstnew(ft_strdup(line), i));
	i++;
}

char	**fill_matrix(t_gnl **lst)
{
	t_gnl	*temp;
	int		i;
	char	**grid;
	
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

static int	handle_map_line(t_map *file, t_gnl **lst, char *line)
{
	if (check_params(file))
	{
		fill_list(lst, line);
		return (1);
	}
	printf("Error\nMap started before all textures/colors were defined.\n");
	return (0);
}

int parse_file(int fd, t_map *file, t_gnl **lst)
{
	char	*line;
	int		i;

	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] >= 65 && line[i] <= 90)
			path_way(fd, file, line);
		else if (line[i] >= '0' && line[i] <= '9')
		{
			if (!handle_map_line(file, lst, line))
			{
				free(line);
				return (0);
			}
		}
		i = 0;
		free(line);
	}
	return (1);
}
