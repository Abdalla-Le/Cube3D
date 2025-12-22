/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:06:09 by ancarlos          #+#    #+#             */
/*   Updated: 2025/12/22 17:12:10 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int parse_map(int fd)
{
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Imprime a linha lida
        free(line);         // MUITO IMPORTANTE: libere a memória para evitar leaks
    }
    return 1;
}