/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:26:27 by ancarlos          #+#    #+#             */
/*   Updated: 2025/08/07 15:35:32 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_free_matrix(char **matrix)
{
    int i;

    i = 0;
	while (matrix[i])
    {
		free(matrix[i]);
        i++;
    }
	free(matrix);
    return (1);
}