/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:51:43 by ancarlos          #+#    #+#             */
/*   Updated: 2025/03/22 15:36:42 by ancarlos         ###   ########.fr       */
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
	while (n != 0)
	{
		n /= 10;
		nlen++;
	}
	return (nlen);
}

int	perc_p(void	*p)
{
	int				i;
	int				ret;
	char			*str;
	unsigned long	log;

	log = (unsigned long)p;
	i = 0;
	str = malloc(intlen(log));
	if (!p)
	{
		free(str);
		return (perc_s("(nil)"));
	}
	while (log > 0)
	{
		str[i++] = "0123456789abcdef"[log % 16];
		log = log / 16;
	}
	ret = i--;
	ret += write(1, "0x", 2);
	if (i >= 0)
		while (i >= 0)
			write(1, &str[i--], 1);
	free(str);
	return (ret);
}
