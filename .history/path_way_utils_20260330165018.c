/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_way_utils_20260330165018.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:12:58 by ancarlos          #+#    #+#             */
/*   Updated: 2026/03/30 17:06:15 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static int	is_xpm(char *path)
{
	int	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 5 || ft_strncmp(&path[len - 4], ".xpm", 4) != 0)
		return (0);
	return (1);
}

char	*get_clean_path(char *line)
{
	char	*temp;
	int		i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	i += 2;
	while (line[i] && line[i] == ' ')
		i++;
	temp = ft_strtrim(&line[i], " \n");
	if (!is_xpm(temp))
	{
		printf("Error\nInvalid texture extension: %s\n", temp);
		free(temp);
		return (NULL);
	}
	return (temp);
}


int	take_color(char **rgb)
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
