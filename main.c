/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:00:56 by ancarlos          #+#    #+#             */
/*   Updated: 2025/12/23 18:48:25 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int main (int ac, char **av)
{
	int	fd;
	t_map	map;
	t_gnl	*lst;

	lst = NULL;
	if (!(fd = stdin_parse(av[1])) || ac != 2)
		return (1);
	parse_file(fd, map, lst);
	while (lst != NULL)
    {
        // Supondo que o 'content' seja uma string (char *)
        printf("Conteúdo: %s\n", lst->line);
        
        // Move para o próximo nó
        lst = lst->next;
    }
	
}