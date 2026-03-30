/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_20260330165018.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:00:56 by ancarlos          #+#    #+#             */
/*   Updated: 2026/03/30 17:06:15 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void print_teste(t_map *file)
{
	printf("%s\n%s\n%s\n%s",file->ea_path, file->no_path, file->we_path, file->so_path);
	printf("\n%d e %d\n", file->ceil_color, file->floor_color);
}

// int main (int ac, char **av)
// {
// 	int	fd;
// 	t_map	*file;
// 	t_gnl	*map;

// 	map = NULL;
// 	if (!(fd = stdin_parse(av[1])) || ac != 2)
// 		return (1);
// 	file = malloc(sizeof(t_map));
// 	if (!parse_file(fd, file, &map))
// 	{
// 		free_map_struct(file);
// 		return (1);
// 	}
// 	file->grid = fill_matrix(&map, file);
// 	if (!parse_map(file))
// 	{
// 		free_map_struct(file);
// 		return (1);
// 	}
// 	print_teste(file);
// 	while (map != NULL)
//     {
//         printf("INDEX: %d -- Conteúdo: %s", map->index, map->line);

//         map = map->next;
//     }

// 	int i = 0;
// 	char **grid;

// 	puts("GRID ABAIXO \n");
// 	grid = file->grid;
// 	while (grid[i])
// 	{
//    		printf("%s\n", grid[i]);
//     	i++;
// 	}
// }

int	main(int ac, char **av)
{
	t_map	*map;
	int		i;

	// 1. Check de argumento básico
	if (ac != 2)
	{
		printf("Error\nUso correto: ./cub3D <mapa.cub>\n");
		return (1);
	}

	// 2. O GRANDE TESTE: Chama sua função modular
	// Se retornar NULL, o erro já foi printado lá dentro (Flood Fill, Cores, etc)
	map = init_parse(av[1]);
	if (!map)
		return (1);

	// 3. Print de Debug para conferir o que você vai entregar pra dupla
	printf("--- PARSE OK ---\n");
	printf("Textura NO: [%s]\n", map->no_path);
	printf("Textura SO: [%s]\n", map->so_path);
	printf("Textura WE: [%s]\n", map->we_path);
	printf("Textura EA: [%s]\n", map->ea_path);
	printf("Cor Chão (INT): %d\n", map->floor_color);
	printf("Cor Teto (INT): %d\n", map->ceil_color);
	printf("Player em: Y[%d] X[%d] Direção[%c]\n", map->p_y, map->p_x, map->p_dir);
	printf("Dimensões: %d x %d\n", map->width, map->height);

	printf("\n--- GRID NORMALIZADO ---\n");
	i = 0;
	while (map->grid[i])
	{
		printf("|%s|\n", map->grid[i]); // O | serve para ver se os espaços de preenchimento estão lá
		i++;
	}

	// 4. Limpeza final (Obrigatório para não ter leak)
	free_map_struct(map);
	return (0);
}
