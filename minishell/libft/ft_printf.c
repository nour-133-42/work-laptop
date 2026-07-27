/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:18:40 by helfayez          #+#    #+#             */
/*   Updated: 2026/07/19 19:18:33 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	xxcsp(char format_v2, va_list args, va_list copy, int count)
{
	if (format_v2 == 'X')
	{
		ft_putnbr_hc(va_arg(copy, unsigned int));
		count += count_n_h(va_arg(args, unsigned int));
	}
	else if (format_v2 == 'x')
	{
		ft_putnbr_hs(va_arg(copy, unsigned int));
		count += count_n_h(va_arg(args, unsigned int));
	}
	else if (format_v2 == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format_v2 == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format_v2 == 'p')
		count += putp(va_arg(args, unsigned long long));
	else if (format_v2 == '%')
		count += ft_putchar('%');
	else if (format_v2 == 'u')
	{
		ft_putnbr_u(va_arg(copy, unsigned int));
		count += u_count_n(va_arg(args, unsigned int));
	}
	return (count);
}

int	diu(const char *format, va_list args)
{
	int		i;
	int		count;
	va_list	copy;

	count = 0;
	i = 0;
	while (format[i])
	{
		va_copy(copy, args);
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
			{
				ft_putnbr(va_arg(copy, int));
				count += n_count(va_arg(args, int));
			}
			else
				count = xxcsp(format[i], args, copy, count);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	count = diu(format, args);
	va_end(args);
	return (count);
}
