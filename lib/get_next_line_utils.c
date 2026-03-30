/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:02:06 by ancarlos          #+#    #+#             */
/*   Updated: 2025/12/22 16:23:40 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include "../lib/libft.h"

char	*ft_strjoin(const char *s1,const char *s2)
{
	char	*temp;
	char	*s3;
	int		len1 = 0;
	int		len2;

	if (s1)
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = ft_calloc(len1 + len2 + 1, 1);
	if (!s3)
		return (NULL);
	temp = s3;
	if (s1)
		while (*s1)
			*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (s3);
}

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

void	*ft_calloc(size_t num, size_t size)
{
	void			*str;
	int				i;
	unsigned char	*ptr;

	i = 0;
	if (num != 0 && (size * num) / num != size)
		return (NULL);
	str = malloc(num * size);
	if (!str)
		return (NULL);
	ptr = (unsigned char *)str;
	while ((size_t)i < size * num)
		ptr[i++] = '\0';
	return (str);
}

char	*ft_strdup(const char *src)
{
	char	*newstr;
	int		lenght;
	int		i;

	i = 0;
	lenght = ft_strlen(src);
	newstr = (char *)malloc(lenght + 1);
	if (!newstr)
		return (NULL);
	while (src[i])
	{
		newstr[i] = src[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
