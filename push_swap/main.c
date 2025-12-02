/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:22:23 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/02 16:20:47 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dublicates(t_list *a)
{
	int		*tab;
	int		i;
	int		j;
	t_list	*temp;

	tab = malloc(ft_lstlen(a));
	temp = a;
	i = 0;
	while (temp)
	{
		j = 0;
		while (j < i)
		{
			if (temp->content == tab[j])
				return (0);
			j++;
		}
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	free(tab);
	return (1);
}

int	check_not_int(char **a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (a[i][j])
	{
		j = 0;
		while (a[i][j])
		{
			if (a[i][j] < '0' || a[i][j] > '9')
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_list(t_list *a)
{
	t_list	*temp;

	temp = a;
	if (!check_dublicates(a))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (temp)
	{
		if (temp->content > 2147483647 || temp->content < -2147483648)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	first_step(t_list **a, t_list **b, int *i)
{
	t_list	*temp;

	temp = *a;
	if (if_sorted_2(*a))
		return (1);
	while (temp->next->next->next != NULL)
	{
		i += pb(a, b);
		temp = temp->next;
	}
	if (!if_sorted_2(*a))
		*i += sa(a);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		i;

	if (argc > 1)
	{
		if (!check_not_int(argv + 1))
			return (0);
		i = 0;
		a = fill_list(argc, argv);
		b = NULL;
		if (!a || !validate_list(a))
			return (0);
		if (first_step(&a, &b, &i))
			return (0);
		execute_operations(&a, &b);
	}
}
//__INT_MAX__