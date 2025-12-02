/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:22:31 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/01 19:43:15 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_list **lst1, t_list **lst2)
{
	push_last_to_last(lst1, lst2);
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_list **lst1, t_list **lst2)
{
	push_last_to_last(lst1, lst2);
	write(1, "pb\n", 3);
	return (1);
}
