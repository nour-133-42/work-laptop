/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:16:00 by helfayez          #+#    #+#             */
/*   Updated: 2025/09/02 16:13:34 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if (!s)
	{
		ft_putstr("(null)");
		return (ft_strlen("(null)"));
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
