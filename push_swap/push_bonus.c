/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:22:31 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/18 10:18:23 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_list **lst1, t_list **lst2)
{
	push_last_to_last(lst1, lst2);
	return (1);
}

int	pb(t_list **lst1, t_list **lst2)
{
	push_last_to_last(lst1, lst2);
	return (1);
}
