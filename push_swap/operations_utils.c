/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:22:17 by nalshmai          #+#    #+#             */
/*   Updated: 2025/11/01 11:27:17 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_last_two(t_list **lst)
{
	t_list	*current;
	t_list *second_last;
	t_list *last;

	if (!lst || !*lst || !(*lst)->next)
		return ;

	current = *lst;

	while (current->next->next->next)
		current = current->next;

	second_last = current->next;
	last = second_last->next;

	second_last->next = NULL;
	last->next = second_last;
	current->next = last;
}


void	push_last_to_last(t_list **lst1, t_list **lst2)
{
	t_list	*cur;

	if (!lst1 || !*lst1 || !lst2)
		return ;

	cur = *lst1;

	if (!cur->next)
	{
		*lst1 = NULL;
		ft_lstadd_back(lst2, cur);
		return ;
	}

	while (cur->next->next)
		cur = cur->next;

	ft_lstadd_back(lst2, cur->next);
	cur->next = NULL;
}


void	rotate_list(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	*lst = first->next;
	first->next = NULL;
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	reverse_rotate_list(t_list **lst)
{
	t_list	*prev;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	prev = NULL;
	last = *lst;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *lst;
	*lst = last;
}
int	if_sorted_1(t_list *lst)
{
	t_list	*t;
	int		n[3];
	int		m;
	int		i;

	i = 0;
	m = 0;
	n[1] = lst->content;
	n[2] = lst->next->content;
	n[3] = lst->next->next->content;
	if (n[3] > n[2] && n[1] < n[2])
		return (1);
	else if (n[3] < n[1] && n[2] > n[1])
		return (1);
	else if (n[2] < n[3] && n[1] > n[3])
		return (1);
	return (0);
}
