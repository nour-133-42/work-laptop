/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:39:26 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/21 17:43:57 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	check_max_int(int argc, char *argv[])
{
	t_list	*temp;
	t_list	*head;

	temp = fill_list(argc, argv);
	if (!temp)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	argc = 1;
	head = temp;
	while (temp)
	{
		if ((temp->content > 2147483647) || temp->content < -2147483648
			|| ft_strlen(argv[argc]) > 11)
		{
			write(2, "Error\n", 6);
			free_list(head);
			return (0);
		}
		temp = temp->next;
		argc++;
	}
	free_list(head);
	return (1);
}

int	check_dublicates(int argc, char **argv)
{
	int			i;
	int			j;
	long long	v;

	if (argc <= 1)
		return (1);
	i = 1;
	while (i < argc)
	{
		v = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			if (v == ft_atoi(argv[j++]))
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_not_int(char **a)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (a[++i])
	{
		j = 0;
		if ((a[i][j] == '-' || a[i][j] == '+') && a[i][j + 1] != '\0')
			j++;
		if (a[i][j] == '\0')
		{
			write(2, "Error\n", 6);
			return (0);
		}
		while (a[i][j])
		{
			if (a[i][j] < '0' || a[i][j++] > '9')
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
	}
	return (1);
}
