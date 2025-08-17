/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:48:06 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/17 13:31:43 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	find_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

size_t	find_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > find_start(s1, set) && ft_strchr(set, s1[i - 1]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = find_start(s1, set);
	p = malloc(find_end(s1, set) - find_start(s1, set) + 1);
	if (!p || !s1 || !set)
		return (NULL);
	ft_strlcpy(p, s1 + i, find_end(s1, set) - i + 1);
	return (p);
}

/*int	main(void)
{
   char	*i;
   i = ft_strtrim("fdsfsdf", "");
   printf("\"%s\"", i);
   free(i);
}*/