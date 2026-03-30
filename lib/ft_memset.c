/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:17:27 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/18 11:40:56 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	c2;
	char			*s2;

	c2 = (unsigned char)c;
	s2 = (char *)s;
	while (n != 0)
	{
		*s2 = c2;
		s2++;
		n--;
	}
	return ((void *)s);
}

/*#include <stdio.h>
int main()
{
	char s1[20];
	ft_memset(s1, 50, 20);

	printf("%s", s1);
	return 0;
}*/
