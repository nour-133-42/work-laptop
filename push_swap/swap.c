/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:22:41 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/01 19:42:33 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list **lst)
{
	swap_last_two(lst);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_list **lst)
{
	swap_last_two(lst);
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_list **lst1, t_list **lst2)
{
	swap_last_two(lst1);
	swap_last_two(lst2);
	write(1, "ss\n", 3);
	return (1);
}
