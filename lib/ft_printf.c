/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:03:43 by ancarlos          #+#    #+#             */
/*   Updated: 2025/01/28 16:35:52 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static void	fill(const char *print, int i, int *ret, va_list args)
{
	if (print[i] == 'c')
		*ret += perc_c(va_arg(args, int));
	else if (print[i] == 's')
		*ret += perc_s(va_arg(args, char *));
	else if (print[i] == 'i' || print[i] == 'd')
		*ret += perc_d(va_arg(args, int));
	else if (print[i] == 'x')
		*ret += perc_x(va_arg(args, unsigned int));
	else if (print[i] == 'X')
		*ret += perc_xupper(va_arg(args, unsigned int));
	else if (print[i] == 'p')
		*ret += perc_p(va_arg(args, void *));
	else if (print[i] == '%')
		*ret += write(1, "%", 1);
	else if (print[i] == 'u')
		*ret += perc_u(va_arg(args, unsigned int));
}

int	ft_printf(const char *print, ...)
{
	va_list	args;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	if (!print)
		return (-1);
	va_start(args, print);
	while (print[i])
	{
		if (print[i] == '%' && print[i + 1])
		{
			i++;
			fill(print, i, &ret, args);
		}
		else
		{
			write(1, &print[i], 1);
			ret++;
		}
		i++;
	}
	return (ret);
}
