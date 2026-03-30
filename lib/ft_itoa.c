/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:40:54 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/19 15:45:18 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	l;

	l = 0;
	if (n < 0)
	{
		n *= -1;
		l++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static char	*rest(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 2147483647)
		return (ft_strdup("2147483647"));
	return (0);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	size_t	dig;
	int		i;

	dig = intlen((long)n);
	if ((n == 0) || (n == 2147483647) || (n == -2147483648))
		return (rest(n));
	itoa = malloc(dig + 1);
	if (!itoa)
		return (NULL);
	i = dig;
	dig = 0;
	itoa[i] = '\0';
	if (n < 0)
	{
		itoa[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		dig = (n % 10) + 48;
		itoa[(--i)] = dig;
		n = n / 10;
	}
	return (itoa);
}
/* #include <stdio.h>
int main()
{
	printf("%s",ft_itoa(-0));
	return 0;
} */
