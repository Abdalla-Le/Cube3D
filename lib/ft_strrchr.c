/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:37:35 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/18 13:51:40 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	int	i;

	i = ft_strlen(s1);
	if (c >= 256)
		c -= 256;
	if (c == '\0')
		return ((char *)&s1[i]);
	while (i >= 0)
	{
		if (s1[i] == c)
			return ((char *)&s1[i]);
		i--;
	}
	return (NULL);
}

/* #include <stdio.h>
int main()
{
	char	*s1 = "bonjour";

	printf("%s",ft_strrchr(s1 + 2, ''));
	return 0;
} */
