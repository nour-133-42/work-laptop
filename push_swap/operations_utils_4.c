/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:30:12 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/02 16:00:51 by nalshmai         ###   ########.fr       */
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
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
