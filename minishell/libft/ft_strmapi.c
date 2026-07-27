/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:03:29 by helfayez          #+#    #+#             */
/*   Updated: 2025/08/26 14:15:42 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	j;
	char	*mallo;

	if (!s || !f)
		return (NULL);
	j = 0;
	mallo = malloc(ft_strlen(s) + 1);
	if (!mallo)
		return (NULL);
	while (s[j] != '\0')
	{
		mallo[j] = f(j, s[j]);
		j++;
	}
	mallo[j] = '\0';
	return (mallo);
}
/*int main()
{
ft_striteri("hamdan",);
}*/