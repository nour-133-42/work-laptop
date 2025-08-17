/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:56:30 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/17 20:30:05 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

size_t	count_params(char *s)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s[i + 1])
	{
		if (s[i] == '%' && s[i + 1] != '%')
			r++;
		i++;
	}
	if (s[i] == '%' && s[i - 1] != '%')
		return (r);
}
unsigned int	ft_putunpr(int n)
{
	return ((unsigned int)n);
}
ft_printf(const char *s, ...)
{
	size_t	i;
	va_list	args;

	i = 0;
	if (!s)
		return (NULL);
	va_start(args, count_params(s));
	while (s[i])
	{
		if (s[i++] == '%')
		{
			if (s[i] == 'c')
				ft_putchar(va_arg(args, char));
			else if (s[i] == 's')
				ft_putstr(va_arg(args, char *));
			else if (s[i] == 'i')
				ft_putnbr(va_arg(args, int));
			else if (s[i] == 'd')
				ft_putnbr(va_arg(args, int));
			else if (s[i] == 'u')
				ft_putunbr(va_arg(args, unsigned int));
		}
		else
			ft_putchar(s[i]);
	}
}
