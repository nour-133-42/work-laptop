/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:22:23 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/18 14:09:05 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_step(t_list **a, t_list **b, int *i)
{
	t_list	*temp;

	temp = *a;
	if (if_sorted_2(*a))
		return (1);
	if (ft_lstlen(*a) == 2)
	{
		sort_two(a);
		return (1);
	}
	while (temp->next->next->next != NULL)
	{
		temp = temp->next;
		*i += pb(a, b);
	}
	if (!if_sorted_2(*a))
	{
		sort_three(a);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		i;

	if (argc > 1)
	{
		if (!check_not_int(argv + 1) || !check_max_int(argc, argv)
			|| !check_dublicates(argc, argv))
			return (0);
		i = 0;
		a = fill_list(argc, argv);
		b = NULL;
		if (first_step(&a, &b, &i))
		{
			free_list(a);
			free_list(b);
			return (0);
		}
		execute_operations(&a, &b);
		sort_final(&a);
		free_list(a);
		free_list(b);
	}
}
