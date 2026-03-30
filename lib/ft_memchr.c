/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:43:09 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/19 15:22:01 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	const unsigned char	*ptr2;

	ptr2 = ptr;
	if (value == 0 && n == 0)
		return (NULL);
	if (value == '\0')
		return ((char *)(ptr2 + ft_strlen(ptr)));
	ptr2 = (const unsigned char *)ptr;
	while (n-- > 0)
	{
		if (*ptr2 == (unsigned char)value)
			return ((void *)ptr2);
		ptr2++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>
int main()
{

	char s[] = {0, 1, 2 ,3 ,4 ,5};

	printf("%s----->1", (char *)memchr(s, '\0', 3));
	printf("\n");
	printf("%s----->2", (char *)ft_memchr(s, '\0', 3));

	return 0;
} */
