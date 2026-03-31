/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:39:09 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 15:39:32 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_wall(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map_size[1] || y >= data->map_size[0])
		return (1);
	return (data->map[x][y] != 0);
}
