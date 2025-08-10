/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 08:11:37 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 09:05:58 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	test_ft_atoi(void)
{
	printf("ft_atoi: ");
	printf("%d == %d\n", ft_atoi("42"), 42);
}

void	test_ft_bzero(void)
{
	char	s[5] = "abcd";

	ft_bzero(s, 4);
	printf("ft_bzero: ");
	for (int i = 0; i < 4; i++)
		printf("%d ", s[i]);
	printf("\n");
}

void	test_ft_calloc(void)
{
	char	*ptr;

	ptr = ft_calloc(5, sizeof(char));
	printf("ft_calloc: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", ptr[i]);
	free(ptr);
	printf("\n");
}

void	test_ft_is_functions(void)
{
	printf("ft_isalpha: %d == %d\n", ft_isalpha('A'), isalpha('A'));
	printf("ft_isdigit: %d == %d\n", ft_isdigit('5'), isdigit('5'));
	printf("ft_isalnum: %d == %d\n", ft_isalnum('3'), isalnum('3'));
	printf("ft_isascii: %d == %d\n", ft_isascii(127), isascii(127));
	printf("ft_isprint: %d == %d\n", ft_isprint(32), isprint(32));
}

void	test_ft_mem_functions(void)
{
	char	a[] = "12345";
	char	b[] = "abcde";
	char	c[] = "hello";
	char	d[5] = "test";

	ft_memcpy(a, b, 3);
	printf("ft_memcpy: %s\n", a);
	ft_memmove(c + 2, c, 3);
	printf("ft_memmove: %s\n", c);
	ft_memset(d, 'x', 3);
	printf("ft_memset: %s\n", d);
}

void	test_ft_strlen(void)
{
	printf("ft_strlen: %lu == %lu\n", (unsigned long)ft_strlen("hello"),
		strlen("hello"));
}

void	test_ft_strdup(void)
{
	char	*dup;

	dup = ft_strdup("copy");
	printf("ft_strdup: %s\n", dup);
	free(dup);
}

void	test_ft_split(void)
{
	char	**result;

	result = ft_split("hello world 42", ' ');
	printf("ft_split: ");
	for (int i = 0; result[i]; i++)
	{
		printf("[%s] ", result[i]);
		free(result[i]);
	}
	free(result);
	printf("\n");
}

void	test_ft_itoa(void)
{
	char	*s;

	s = ft_itoa(-123);
	printf("ft_itoa: %s\n", s);
	free(s);
}

void	test_ft_strjoin(void)
{
	char	*joined;

	joined = ft_strjoin("hello", "world");
	printf("ft_strjoin: %s\n", joined);
	free(joined);
}

void	test_ft_strtrim(void)
{
	char	*trimmed;

	trimmed = ft_strtrim("   hello   ", " ");
	printf("ft_strtrim: [%s]\n", trimmed);
	free(trimmed);
}

void	test_ft_substr(void)
{
	char	*sub;

	sub = ft_substr("hello", 1, 3);
	printf("ft_substr: %s\n", sub);
	free(sub);
}

void	test_ft_putchar_fd(void)
{
	printf("ft_putchar_fd: ");
	ft_putchar_fd('X', 1);
	printf("\n");
}

void	test_ft_putstr_fd(void)
{
	printf("ft_putstr_fd: ");
	ft_putstr_fd("Hello", 1);
	printf("\n");
}

void	test_ft_putendl_fd(void)
{
	printf("ft_putendl_fd: ");
	ft_putendl_fd("Line", 1);
}

void	test_ft_putnbr_fd(void)
{
	printf("ft_putnbr_fd: ");
	ft_putnbr_fd(12345, 1);
	printf("\n");
}

// You can add similar tests for strncmp, strnstr, strrchr, strlcat, strlcpy,
// strmapi, striteri, strchr, etc.

int	main(void)
{
	test_ft_atoi();
	test_ft_bzero();
	test_ft_calloc();
	test_ft_is_functions();
	test_ft_mem_functions();
	test_ft_strlen();
	test_ft_strdup();
	// test_ft_split();
	test_ft_itoa();
	test_ft_strjoin();
	test_ft_strtrim();
	test_ft_substr();
	test_ft_putchar_fd();
	test_ft_putstr_fd();
	test_ft_putendl_fd();
	test_ft_putnbr_fd();
	// Add more tests as needed
	return (0);
}
