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

#include "parse.h"

static int	take_color(char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return ((r << 16) | (g << 8) | (b));
}

static int	parse_color(char *line)
{
	char	**rgb_colors;
	char	**split_aux;
	int		real_rgb;
	int		i;

	i = 0;
	split_aux = ft_split(line, ' ');
	rgb_colors = ft_split(split_aux[1], ',');
	while (i++ < 3)
		rgb_colors[i] = ft_strtrim(rgb_colors[i], " ");
	real_rgb = take_color(rgb_colors);

	my_free_matrix(split_aux);
	my_free_matrix(rgb_colors);
	return (real_rgb);
}

static int	find_color(char *line, t_map *file)
{
	(void)line;
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'C' || line[i] == 'F')
	{
		if (line[i] == 'C')
			file->ceil_color = parse_color(line);
		else
			file->floor_color = parse_color(line);
		return (1);
	}
	return (0);
}


static int	find_way(char *line, t_map *file)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'E' || line[i] == 'W' || line[i] == 'S' || line[i] == 'N' )
	{
		if (line[i] == 'E')
			file->ea_path = ft_strdup(line);
		if (line[i] == 'W')
			file->we_path = ft_strdup(line);
		if (line[i] == 'S')
			file->so_path = ft_strdup(line);
		if (line[i] == 'N')
			file->no_path = ft_strdup(line);
		return (1);
	}
	return (0);
}

int	path_way(int fd, t_map *file, char *line)
{
	(void)fd;
	if ((line[0] >= 65 && line[0] <= 90) || line[0] == ' ')
	{
		if (!find_color(line, file) && !find_way(line, file))
			return 0;
	}
	return (1);
}
