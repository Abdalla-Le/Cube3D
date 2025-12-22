/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:11:16 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/19 15:39:46 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest2;
	unsigned const char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned const char *)src;
	if (dest < src)
		return (ft_memcpy(dest2, src2, n));
	while (n-- != 0)
		dest2[n] = src2[n];
	return (dest2);
}
/* #include <stdio.h>
#include <string.h>
int main()
{
	char *s1 = "dale, dele";
	//char s2[] = "aaaaaaaaaaaaaaaa";
	//char *s3 = "dale, dele";
	//char s4[] = "aaaaaaaaaaaaaaaa";

	char	*sdale = ft_memmove(NULL, s1 + 3, 50);
	printf("%s\n", sdale);
	//memmove(s4, s3,5);
	//printf("%s\n", s4);
	return 0;
} */
