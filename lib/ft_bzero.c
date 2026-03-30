/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:00:34 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/01 17:13:26 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n != 0)
	{
		(*(char *)s) = 0;
		s++;
		n--;
	}
}
/*#include <stdio.h>
int main()
{
	char s1[20];
	ft_bzero(s1, 20);

	printf("%s", s1);
	return 0;
}*/
