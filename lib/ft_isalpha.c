/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:33:45 by ancarlos          #+#    #+#             */
/*   Updated: 2024/09/25 14:17:09 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*#include <stdio.h>
int main()
{
	char dale = 'c';
	char dale2 = 'C';
	char *dale3 = "AbcdEfghijlmnopqrstuvxz";
	int i;
	int j;


	while(dale3[i])
	{
		if(ft_isalpha(dale3[i]) == 1)
			j++;
		i++;
	}
	printf("%d\n", ft_isalpha(dale));
	printf("%d\n", ft_isalpha(dale2));
	printf("%d\n", j);
	return 0;
}*/
