/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:20:53 by ancarlos          #+#    #+#             */
/*   Updated: 2026/03/31 21:12:31 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void	free_map_struct(t_map *map)
{
	if (!map)
		return ;
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->we_path)
		free(map->we_path);
	if (map->ea_path)
		free(map->ea_path);
	if (map->grid)
		my_free_matrix(map->grid);
	free(map);
}

void	free_map_fields(t_map *map)
{
	if (!map)
		return ;
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->we_path)
		free(map->we_path);
	if (map->ea_path)
		free(map->ea_path);
	if (map->grid)
		my_free_matrix(map->grid);
}

void	free_lst(t_gnl *lst)
{
	t_gnl	*temp;

	while (lst != NULL)
	{
		temp = lst->next;
		free(lst->line);
		free(lst);
		lst = temp;
	}
}
