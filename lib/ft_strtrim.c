/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:35:25 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/17 19:48:58 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verify(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len1;
	size_t	i;
	size_t	start;
	size_t	zero;
	char	*s3;

	i = 0;
	zero = 0;
	start = 0;
	len1 = ft_strlen(s1);
	while (verify(s1[i], set) == 1)
		i++;
	start = i;
	i = len1;
	while (verify(s1[i - 1], set) == 1)
		i--;
	if (start >= i)
		return (ft_strdup(""));
	s3 = malloc(i - start + 1);
	if (!s3)
		return (NULL);
	while (start < i)
		s3[zero++] = s1[start++];
	s3[zero] = '\0';
	return (s3);
}
/*#include <stdio.h>
int main()
{
	char *s1 = "   x xxxHello, how are you   xxx";
	char *s2 = " x";
	printf("%s",ft_strtrim(s1, s2));
	return 0;
}*/
