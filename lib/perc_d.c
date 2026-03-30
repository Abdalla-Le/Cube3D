/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:03:42 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/28 16:04:59 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	perc_d(int nb)
{
	int	print_ret;

	print_ret = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		print_ret++;
		nb = nb * -1;
	}
	if (nb >= 0 && nb <= 9)
	{
		print_ret++;
		ft_putchar(nb + 48);
	}
	else if (nb > 9)
	{
		print_ret += perc_d((nb / 10));
		print_ret += perc_d((nb % 10));
	}
	return (print_ret);
}
