/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:43:16 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/17 13:54:36 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!big)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	while (big[++i] && i < len)
	{
		if (big[i] == *little)
		{
			j = 0;
			while (big[i + j] == little[j] && (i + j) < len)
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
	}
	return (NULL);
}
/* #include <bsd/string.h>
#include <stdio.h>
int main()
{
    char    *s1 = "aaabcabcd";
    char    *s2 = "aabc";
	char    *s3 = "aaabcabcd";
    char    *s4 = "aabc";
	//char	*ptr = strnstr(s3, s4, 100);

    printf("%s\n",ft_strnstr(s1, s2, -1));
	printf("%s\n", strnstr(s3, s4, -1));

    return 0;
} */
