/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:35:19 by helfayez          #+#    #+#             */
/*   Updated: 2025/08/25 16:41:57 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
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
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*mallo;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count(n);
	mallo = malloc(len + 1);
	if (!mallo)
		return (NULL);
	if (n < 0)
	{
		mallo[0] = '-';
		n = -n;
	}
	mallo[len] = '\0';
	while (n)
	{
		mallo[--len] = '0' + (n % 10);
		n /= 10;
	}
	return (mallo);
}
