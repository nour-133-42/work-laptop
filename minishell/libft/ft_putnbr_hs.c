/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:13:33 by helfayez          #+#    #+#             */
/*   Updated: 2025/09/02 17:49:41 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hs(unsigned long long n)
{
	char	c;
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putnbr_hs(n / 16);
	}
	c = hex[n % 16];
	write(1, &c, 1);
}
