/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:06:38 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/15 16:08:43 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = malloc(ft_strlen(s) + 1);
	while ((*s))
	{
		s2[i] = f(i, *s);
		i++;
		s++;
	}
	s2[i] = '\0';
	return (s2);
}

/*#include <stdio.h>
int main()
{
	printf("STRMAPI:\noriginal:%s\n\n", ft_strmapi("strmapi is right!", to_upp));
	return 0;
}*/
