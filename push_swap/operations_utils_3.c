/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:00:11 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/02 16:00:17 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assien_price(t_list **lst)
{
	t_list	*current;

	current = *lst;
	while (current)
	{
		if (current->chepest_rotation == current->target->chepest_rotation)
		{
			current->price = current->to_top_cost
				- current->target->to_top_cost;
			if (current->price < 0)
				current->price *= -1;
		}
		else
			current->price = current->to_top_cost
				+ current->target->to_top_cost;
		current = current->next;
	}
}

t_list	*assien_chepest_node(t_list **lst)
{
	t_list	*current;
	t_list	*chepestnode;

	current = *lst;
	chepestnode = *lst;
	while (current)
	{
		if (chepestnode->price > current->price)
			chepestnode = current;
		current = current->next;
	}
	chepestnode->chepest_node = 1;
	return (chepestnode);
}

void	preform_same_rotation(t_list **a, t_list **b, t_list *chepestnode,
		int *i)
{
	if (chepestnode->chepest_rotation == 1)
	{
		while (chepestnode != *b || chepestnode->target != *a)
			*i += rr(a, b);
		if (chepestnode == *b)
			while (chepestnode->target != *a)
				*i += ra(a);
		else
			while (chepestnode != *b)
				*i += rb(b);
	}
	else
	{
		while (chepestnode != *b || chepestnode->target != *a)
			*i += rrr(a, b);
		if (chepestnode == *b)
			while (chepestnode->target != *a)
				*i += rra(a);
		else
			while (chepestnode != *b)
				*i += rrb(b);
	}
}

int	get_chepest_node_to_top(t_list **a, t_list **b, t_list *chepestnode)
{
	int	i;

	i = 0;
	if (chepestnode->chepest_rotation == chepestnode->target->chepest_rotation)
		preform_same_rotation(a, b, chepestnode, &i);
	else
		i += preform_different_rotation(a, b, chepestnode);
	return (i);
}

int	execute_operations(t_list **a, t_list **b)
{
	t_list	*chepestnode;
	int		i;

	i = 0;
	while (b)
	{
		assien_targets(a, b);
		assien_to_top_cost(a);
		assien_to_top_cost(b);
		assien_price(b);
		chepestnode = assien_chepest_node(b);
		i += get_chepest_node_to_top(a, b, chepestnode);
		i += pa(b, a);
	}
	return (i);
}
