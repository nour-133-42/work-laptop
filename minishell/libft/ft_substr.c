/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 09:54:01 by helfayez          #+#    #+#             */
/*   Updated: 2025/08/16 13:54:49 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mal;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	mal = (char *)malloc(len + 1);
	if (!mal)
		return (NULL);
	while (len > i)
	{
		mal[i] = s[start + i];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}
// int main(){
// char ha[]  ="hamdan";
// printf("%s",ft_substr(ha,1,3));

// }
