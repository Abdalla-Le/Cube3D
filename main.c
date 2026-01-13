/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:00:56 by ancarlos          #+#    #+#             */
/*   Updated: 2026/01/13 14:15:19 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void print_teste(t_map *file)
{
	printf("%s\n%s\n%s\n%s",file->ea_path, file->no_path, file->we_path, file->so_path);
}

int main (int ac, char **av)
{
	int	fd;
	t_map	*file;
	t_gnl	*map;

	map = NULL;
	if (!(fd = stdin_parse(av[1])) || ac != 2)
		return (1);
	file = malloc(sizeof(t_map));
	parse_file(fd, file, &map);
	file->grid = fill_matrix(&map);
	print_teste(file);
	while (map != NULL)
    {
        printf("INDEX: %d -- Conteúdo: %s", map->index, map->line);

        map = map->next;
    }

	int i = 0;
	char **grid;

	grid = file->grid;
	while (grid[i])
	{
   		printf("%s\n", grid[i]);
    	i++;
	}
}
