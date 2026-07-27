/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:51:02 by helfayez          #+#    #+#             */
/*   Updated: 2025/09/02 17:49:26 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hp(unsigned long long n)
{
	char	c;
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putnbr_hp(n / 16);
	}
	c = hex[n % 16];
	write(1, &c, 1);
}

int	count_n_hp(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len++;
	}
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}
