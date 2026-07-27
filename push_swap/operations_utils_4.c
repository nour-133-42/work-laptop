/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:30:12 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/06 18:45:12 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	preform_different_rotation(t_list **a, t_list **b, t_list *chepestnode)
{
	int	i;

	i = 0;
	if (chepestnode->chepest_rotation == 1)
	{
		while (chepestnode != *b)
			i += rb(b);
		while (chepestnode->target != *a)
			i += rra(a);
	}
	else
	{
		while (chepestnode != *b)
			i += rrb(b);
		while (chepestnode->target != *a)
			i += ra(a);
	}
	return (i);
}

int	if_sorted_2(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	sort_three(t_list **a)
{
	int	x;
	int	y;
	int	z;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	x = (*a)->content;
	y = (*a)->next->content;
	z = (*a)->next->next->content;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	sort_final(t_list **a)
{
	t_list	*min;

	assien_to_top_cost(a);
	min = find_min(*a);
	while (*a != min)
	{
		if (min->chepest_rotation == 1)
			ra(a);
		else
			rra(a);
	}
}
