/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:40:09 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/16 18:41:54 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		slen;
	size_t		dlen;
	size_t		i;
	size_t		to_copy;

	dlen = 0;
	slen = 0;
	to_copy = 0;
	while (dest[dlen] != '\0' && dlen < size)
		dlen++;
	if (dlen == size)
		return (dlen + ft_strlen(src));
	slen = ft_strlen(src);
	to_copy = size - dlen - 1;
	if (to_copy > slen)
		to_copy = slen;
	i = 0;
	while (to_copy > i)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + to_copy] = '\0';
	return (dlen + slen);
}

/* #include <stdio.h>
#include <bsd/string.h>
int	main()
{
	int		a;
	int		b;
	char s1[0] = "\0";
	char s2[11] = "lorem ipsum";
	char s3[0] = "\0";
	char s4[11] = "lorem ipsum";


	a = strlcat(s1, s2, 15);
	b = ft_strlcat(s3, s4, 15);
	printf("%s\n", s1);
	printf("%s\n", s3);
	printf("%d\n", a);
	printf("%d\n", b);

} */
