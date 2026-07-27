/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_n_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:05:25 by helfayez          #+#    #+#             */
/*   Updated: 2025/09/02 16:09:19 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_n_h(unsigned int n)
{
	int				len;
	unsigned long	tmp;

	len = 0;
	tmp = n;
	if (tmp == 0)
		len++;
	while (tmp)
	{
		len++;
		tmp /= 16;
	}
	return (len);
}
