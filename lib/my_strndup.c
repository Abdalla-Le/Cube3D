/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 16:43:18 by ancarlos          #+#    #+#             */
/*   Updated: 2025/09/12 16:47:14 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"  

char	*my_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*dup;

	if (!s)
		return (NULL);

	len = ft_strlen(s);
	if (len > n)
		len = n;

	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);

	ft_strlcpy(dup, s, len + 1);
	return (dup);
}