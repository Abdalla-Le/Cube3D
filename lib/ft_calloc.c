/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:14:31 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/17 11:23:33 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*str;

	if (num != 0 && (size * num) / num != size)
		return (NULL);
	str = malloc(num * size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, num * size);
	return (str);
}

/*#include <stdio.h>

int main()
{
	int *arr;

	arr = ft_calloc(2147483647, sizeof(int));

	if (arr == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Exibe os valores do array (deve ser 0 para todos)
    for (int i = 0; i < 2147483647; i++) {
        printf("%d ", arr[i]);
    }


	return 0;
}*/
