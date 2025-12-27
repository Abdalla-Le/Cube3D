/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:48:28 by ancarlos          #+#    #+#             */
/*   Updated: 2025/12/27 16:43:41 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void fill_list(t_gnl **lst, char *line)
{
	ft_lstadd_back(lst,ft_lstnew(ft_strdup(line)));
}

int parse_map(int fd, t_map *file, char *line, t_gnl **lst)
{
	(void)fd;
	(void)file;
	fill_list(lst, line);
	return 1;
}