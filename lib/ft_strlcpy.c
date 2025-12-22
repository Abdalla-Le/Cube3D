/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:23:18 by ancarlos          #+#    #+#             */
/*   Updated: 2025/03/22 15:28:32 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(const char *i)
{
	int	j;

	j = 0;
	while (i[j])
		j++;
	return (j);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (len(src));
	else if (size > 0)
	{
		while (src[i] != '\0' && i < size -1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (len (src));
}
/*#include <stdio.h>
int	main()
{
	char origen[] = "joao bolos";
	char dest[20];
	char ori[] = "joao bolos";
	char	dest2[20];

	strlcpy(dest, origen, 0);
	ft_strlcpy(dest2, ori, 0);

	size_t a = strlcpy(dest, origen, 0);
	size_t b = ft_strlcpy(dest2, ori, 0);

	printf("ori:--> %s\n", dest);
	printf("minha:--> %s\n", dest2);

	printf("minha:--> %zu\n", a);
	printf("minha:--> %zu\n", b);
}*/
