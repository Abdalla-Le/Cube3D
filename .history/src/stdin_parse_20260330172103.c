/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:07:50 by ancarlos          #+#    #+#             */
/*   Updated: 2026/03/30 17:21:03 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static int check_name(char *file_name)
{
	char	*aux;

	aux = ft_strchr(file_name, '.');
	if (!aux || my_strcmp(aux, ".cub") != 0)
	{
		perror("Error\nThe map file must end in \".cub\"\nExemple: \"file.cub\"");
		return	(0);
	}
	return (1);
}

static int open_file(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		perror("Error\nFail to open file");

	return (fd);
}

int stdin_parse(char *file_name)
{
	int	fd;

	fd = open_file(file_name);
	if (!check_name(file_name) || fd == -1)
		return (0);
	return (fd);
}
