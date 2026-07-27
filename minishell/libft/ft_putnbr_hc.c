/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:13:30 by helfayez          #+#    #+#             */
/*   Updated: 2025/09/02 17:49:34 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hc(unsigned long long n)
{
	char	c;
	char	*hex;

	hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_putnbr_hc(n / 16);
	}
	c = hex[n % 16];
	write(1, &c, 1);
}
