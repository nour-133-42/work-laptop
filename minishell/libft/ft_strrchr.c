/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:58:50 by helfayez          #+#    #+#             */
/*   Updated: 2025/08/26 14:16:21 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	last = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			last = (char *)&s[i];
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (last);
}
/*#include<stdio.h>
int	main(void){
char t[] ="hamdan";
printf("%s",strchr(t,'p'));


}*/
