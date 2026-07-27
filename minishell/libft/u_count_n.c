/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_count_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:11:59 by helfayez          #+#    #+#             */
/*   Updated: 2025/09/02 16:15:23 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_count_n(unsigned int n)
{
	int		len;
	long	tmp;

	len = 0;
	tmp = n;
	if (tmp == 0)
		len++;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	return (len);
}
