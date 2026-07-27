/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:16:22 by helfayez          #+#    #+#             */
/*   Updated: 2025/09/02 16:19:19 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putp(unsigned long long p)
{
	if (!p)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	ft_putnbr_hp(p);
	return (count_n_hp(p) + 2);
}
