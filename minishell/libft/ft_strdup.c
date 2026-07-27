/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:20:46 by helfayez          #+#    #+#             */
/*   Updated: 2025/08/20 10:00:09 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*mallo;

	i = 0;
	mallo = (char *)malloc((sizeof(char) * ft_strlen(s) + 1));
	if (!mallo)
		return (NULL);
	while (s[i] != '\0')
	{
		mallo[i] = s[i];
		i++;
	}
	mallo[i] = '\0';
	return (mallo);
}
// int main(){
// char st[] ="hamdan";
// printf("%s",ft_strdup(st));

// }
