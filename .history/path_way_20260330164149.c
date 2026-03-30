/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_way->c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:16:25 by ancarlos          #+#    #+#             */
/*   Updated: 2025/12/23 18:19:08 by ancarlos         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static int	parse_color(char *line)
{
	char	**rgb_colors;
	char	**split_aux;
	int		real_rgb;
	int		i;

	i = 0;
	split_aux = ft_split(line, ' ');
	if (!split_aux || !split_aux[0] || !split_aux[1] || split_aux[2])
	{
		printf("Error\nInvalid color format. Use F r,g,b or C r,g,b\n");
		my_free_matrix(split_aux);
		return (-2);
	}
	rgb_colors = ft_split(split_aux[1], ',');
	if (!rgb_colors || !rgb_colors[0] || !rgb_colors[1]
		|| !rgb_colors[2] || rgb_colors[3])
	{
		printf("Error\nInvalid color format. Use F r,g,b or C r,g,b\n");
		my_free_matrix(split_aux);
		my_free_matrix(rgb_colors);
		return (-2);
	}
	while (i < 3)
	{
		if (rgb_colors[i] && ft_strchr(rgb_colors[i], ' '))
			rgb_colors[i] = ft_strtrim(rgb_colors[i], " ");
		i++;
	}
	real_rgb = take_color(rgb_colors);
	if (real_rgb == -1)
	{
		printf("Error\nInvalid RGB color value (0-255 allowed).\n");
		return (-2);
	}
	my_free_matrix(split_aux);
	my_free_matrix(rgb_colors);
	return (real_rgb);
}

static int	find_color(char *line, t_map *file)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'C' || line[i] == 'F')
	{
		if (line[i + 1] != ' ')
			return (1);
		if ((line[i] == 'C' && file->ceil_color != -1) ||
			(line[i] == 'F' && file->floor_color != -1))
		{
			printf("Error\nColor defined more than once\n");
			return (0);
		}
		if (line[i] == 'C')
			file->ceil_color = parse_color(line);
		else
			file->floor_color = parse_color(line);
		if (file->ceil_color == -2 || file->floor_color == -2)
			return (0);
		return (1);
	}
	return (1);
}

static int	find_way(char *line, t_map *file)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		file->no_path = get_clean_path(line);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		file->so_path = get_clean_path(line);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		file->we_path = get_clean_path(line);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		file->ea_path = get_clean_path(line);
	else
		return (0);
	return (1);
}

// int	path_way(int fd, t_map *file, char *line)
// {
// 	(void)fd;
// 	if ((line[0] >= 65 && line[0] <= 90) || line[0] == ' ')
// 	{
// 		if (!find_color(line, file) || !find_way(line, file))
// 			return 0;
// 	}
// 	return (1);
// }

int	path_way(int fd, t_map *file, char *line)
{
	int	res_way;
	int	res_color;

	(void)fd;
	res_way = find_way(line, file);
	if (res_way == 1)
		return (1);
	res_color = find_color(line, file);
	if (res_color == 1)
		return (1);
	if (res_color == 0)
		return (0);
	return (1);
}
