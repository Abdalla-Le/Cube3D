/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:09:58 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/19 16:46:09 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*s1_2;
	unsigned const char	*s2_2;

	s1_2 = (unsigned const char *)s1;
	s2_2 = (unsigned const char *)s2;
	while (n-- != 0)
	{
		if (*s1_2 != *s2_2)
			return (*s1_2 - *s2_2);
		s1_2++;
		s2_2++;
	}
	return (0);
}

/*#include <stdio.h>

int main()
{
	char s3[] = {0,0,127,0};
	char s4[] = {0, 0, 42,0};
	char *s1 = "aaaaa";
	char *s2 = "aaaaa";
	printf("%d\n", memcmp(s3,s4,0));
	printf("%d\n", ft_memcmp(s3,s4,0));
	return 0;
}*/
