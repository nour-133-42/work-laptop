/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_count.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:16:52 by helfayez          #+#    #+#             */
/*   Updated: 2025/09/02 16:14:20 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	n_count(int n)
{
	int		len;
	long	tmp;

	len = 0;
	tmp = n;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	if (tmp == 0)
		len++;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	return (len);
}
