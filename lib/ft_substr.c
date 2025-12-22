/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:16:47 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/19 15:52:46 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t size)
{
	size_t	i;
	char	*s1;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	if (size > len - start)
		size = len - start;
	if (start >= len)
		return (ft_strdup(""));
	s1 = (char *)malloc(size + 1);
	if (s1 == NULL)
		return (NULL);
	while (i < size)
		s1[i++] = s[start++];
	s1[i] = '\0';
	return (s1);
}

/* #include <stdio.h>
int main()
{
	char *s1 = "tripouille";
	printf("%s",ft_substr(s1, 100, 1));
} */
