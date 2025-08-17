/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 22:30:12 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/17 11:53:56 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "libft.h"

static char	*reverse_array(char *r)
{
	int		i;
	int		j;
	char	temp;

	if (r[0])
	{
		i = 0;
		j = ft_strlen(r) - 1;
		while (i < j)
		{
			temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			i++;
			j--;
		}
		return (r);
	}
	else
		return ("0");
}

int	count_num(int n)
{
	int		i;
	long	e;

	i = 0;
	e = n;
	if (e <= 0)
	{
		i++;
		e = -e;
	}
	while (e)
	{
		i++;
		e /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	long	e;

	e = n;
	i = 0;
	p = malloc(count_num(e) + 1);
	if (!p)
		return (NULL);
	if (e < 0)
	{
		p[i++] = '-';
		e *= -1;
	}
	if (e == 0)
		p[i++] = '0';
	while (e > 0)
	{
		p[i++] = e % 10 + '0';
		e = e / 10;
	}
	p[i] = '\0';
	if (p[0] == '-')
		return (reverse_array(p + 1) - 1);
	return (reverse_array(p));
}
//-2345
//-5432 2345 - 1
// #include <stdio.h>

// int	main(void)
// {
// 	int	e;

// 	e = 0;
// 	printf("%s\n", ft_itoa(7483648));
// }
