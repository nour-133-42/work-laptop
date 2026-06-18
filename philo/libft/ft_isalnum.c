/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:52:03 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 05:43:59 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <unistd.h>
#include "libft.h"

// static int	ft_isalpha(int c)
// {
// 	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
// 		return (0);
// 	return (1);
// }

// static int	ft_isdigit(int c)
// {
// 	if (c < '0' || c > '9')
// 		return (0);
// 	return (1);
// }

int	ft_isalnum(int c)
{
	if (ft_isdigit((char)c) || ft_isalpha((char)c))
		return (1);
	else
		return (0);
}

// #include <unistd.h>
// int main(void)
// {
// 	if(ft_isalnum('#'))
// 		write(1,"r",1);
// }