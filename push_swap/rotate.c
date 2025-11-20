/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:22:37 by nalshmai          #+#    #+#             */
/*   Updated: 2025/11/16 16:37:27 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list **lst)
{
	rotate_list(lst);
	return (1);
}
int	rb(t_list **lst)
{
	rotate_list(lst);
	return (1);
}
int	rr(t_list **lst1, t_list **lst2)
{
	rotate_list(lst1);
	rotate_list(lst2);
	return (1);
}
