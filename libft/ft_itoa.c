/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 22:30:12 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 09:03:26 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

static void	reverse_array(char *arr)
{
	int	temp;
	int	i;

	i = 0;
	while (i < (int)ft_strlen(arr) / 2)
	{
		temp = arr[i];
		arr[i] = arr[ft_strlen(arr) - 1 - i];
		arr[ft_strlen(arr) - 1 - i] = temp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	p = malloc(15);
	if (!p)
		return (NULL);
	if (n == -2147483648)
		return ("-2147483648");
	if (n < 0)
	{
		p[i++] = '-';
		n *= -1;
	}
	while (n >= 10)
	{
		p[i++] = n % 10 + '0';
		n = n / 10;
	}
	p[i++] = n + '0';
	reverse_array(p + 1);
	p[i] = '\0';
	return (p);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	e;

// 	e = -2147;
// 	printf("%s\n", ft_itoa(e));
// }
