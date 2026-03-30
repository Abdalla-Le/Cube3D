/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_xupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:22:48 by ancarlos          #+#    #+#             */
/*   Updated: 2025/03/22 15:53:45 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(unsigned long n)
{
	int	nlen;

	nlen = 0;
	if (n != 0)
	{
		n *= -1;
		nlen++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		nlen++;
	}
	return (nlen);
}

int	perc_xupper(unsigned long nb)
{
	int		i;
	int		ret;
	char	*str;

	i = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	str = malloc(intlen(nb));
	if (!str)
		return (0);
	while (nb > 0)
	{
		str[i++] = "0123456789ABCDEF"[nb % 16];
		nb = nb / 16;
	}
	ret = i--;
	if (i >= 0)
		while (i >= 0)
			write(1, &str[i--], 1);
	free(str);
	return (ret);
}
