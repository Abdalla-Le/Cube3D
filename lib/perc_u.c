/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:28:27 by ancarlos          #+#    #+#             */
/*   Updated: 2025/03/22 15:37:44 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	perc_u(unsigned int nb)
{
	int	print_ret;

	print_ret = 0;
	if (nb >= 1 && nb <= 9)
	{
		print_ret++;
		ft_putchar(nb + 48);
	}
	else if (nb > 9)
	{
		print_ret += perc_u((nb / 10));
		print_ret += perc_u((nb % 10));
	}
	return (print_ret);
}
