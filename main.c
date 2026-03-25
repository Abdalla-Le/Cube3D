/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:00:56 by ancarlos          #+#    #+#             */
/*   Updated: 2026/03/25 16:20:09 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void print_teste(t_map *file)
{
	printf("%s\n%s\n%s\n%s",file->ea_path, file->no_path, file->we_path, file->so_path);
	printf("\n%d e %d\n", file->ceil_color, file->floor_color);
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
	if (!parse_file(fd, file, &map))
		return (0);
	file->grid = fill_matrix(&map, file);
	if (!parse_map(file))
		return (0);
	print_teste(file);
	while (map != NULL)
    {
        printf("INDEX: %d -- Conteúdo: %s", map->index, map->line);

        map = map->next;
    }

	int i = 0;
	char **grid;

	puts("GRID ABAIXO \n");
	grid = file->grid;
	while (grid[i])
	{
   		printf("%s\n", grid[i]);
    	i++;
	}
}
