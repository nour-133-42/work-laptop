/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:45:48 by helfayez          #+#    #+#             */
/*   Updated: 2025/08/25 16:40:15 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*the_word(const char *s, char c, int *i)
{
	char	*word;
	int		start;
	int		len;
	int		j;

	len = 0;
	j = 0;
	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
	{
		len++;
		(*i)++;
	}
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (j < len)
	{
		word[j] = s[start + j];
		j++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_all(char **res, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		r;
	int		words;

	i = 0;
	r = 0;
	if (!s)
		return (NULL);
	words = count_word(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (r < words)
	{
		res[r] = the_word(s, c, &i);
		if (!res[r])
		{
			free_all(res, r);
			return (NULL);
		}
		r++;
	}
	res[r] = NULL;
	return (res);
}

// int main(void)
// {
//     char **arr;
//     int i = 0;

//     arr = ft_split("bonjour je m'appel Arthur", ' ');
//     while (arr[i] != NULL)
//     {
//         printf("string %d : %s\n", i, arr[i]);
//         i++;
//     }
//     return (0);
// }
