/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:05:04 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/17 12:25:35 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	if (c >= 256)
		c -= 256;
	while (*s1)
	{
		if (*s1 == c)
			return ((char *)s1);
		s1++;
	}
	if ((char) c == '\0')
		return ((char *)s1);
	return (0);
}
/* #include <stdio.h>
#include <string.h>
int	main()
{
	char	*s1 = "Eu gosto de pera";
	printf("%s----->\n", strchr(s1, 'g' + 256));
	printf("----->>>>%s\n\n",ft_strchr(s1, 'g' + 256));
	//printf("%d\n\n", strchr(s1, 116));
} */
