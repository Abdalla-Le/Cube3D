/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:04:11 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/16 19:23:31 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	const char		*src2;
	size_t			i;

	i = 0;
	dest2 = (unsigned char *)dest;
	src2 = (const char *)src;
	while (i != n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return ((void *)dest2);
}
/*#include <stdio.h>
int main()
{
	char	s1[30];
	char	s2[] = "Joao BOlos";

	ft_memcpy(s1, s2, 100);
	printf("\n%s\n", s1);
	return 0;
}*/
