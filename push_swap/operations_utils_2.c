/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:59:34 by nalshmai          #+#    #+#             */
/*   Updated: 2025/11/01 11:59:35 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_list *lst)
{
	t_list	*max;
	t_list	*current;

	current = lst;
	max = lst;
	while (current)
	{
		if (current->content > max->content)
			max = current;
		current = current->next;
	}
	return (max);
}

t_list	*find_min(t_list *lst)
{
	t_list	*min;
	t_list	*current;

	current = lst;
	min = lst;
	while (current)
	{
		if (current->content < min->content)
			min = current;
		current = current->next;
	}
	return (min);
}

void	assien_the_target_node(t_list **current_a, t_list **current_b,
		t_list *max)
{
	while ((*current_a))
	{
		if ((*current_a)->content > (*current_b)->content
			&& (*current_b)->content < max->content)
		{
			(*current_b)->target = (*current_a);
			max = (*current_a);
		}
	}
	(*current_b) = (*current_b)->next;
}

void	assien_targets(t_list **a, t_list **b)
{
	t_list	*current_a;
	t_list	*current_b;
	t_list	*max;

	current_a = *a;
	current_b = *b;
	max = find_max(*a);
	while (current_b)
	{
		if (current_b = max)
			current_b->target = find_min(current_a);
		else
			assien_the_target_node(&current_a, &current_b, max);
		current_b = current_b->next;
	}
}

void	assien_to_top_cost(t_list **lst)
{
	t_list	*current;
	int		len;
	int		i;

	current = *lst;
	len = ft_lstlen(*lst);
	i = 0;
	while (current)
	{
		if (i <= len / 2)
		{
			current->to_top_cost = i;
			current->chepest_way_of_rotation = 1;
		}
		else
		{
			current->to_top_cost = len - i;
			current->chepest_way_of_rotation = 2;
		}
		current = current->next;
	}
}
