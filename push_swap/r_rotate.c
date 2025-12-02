/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:22:34 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/01 19:43:01 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_list **lst)
{
	reverse_rotate_list(lst);
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_list **lst)
{
	reverse_rotate_list(lst);
	write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_list **lst1, t_list **lst2)
{
	reverse_rotate_list(lst1);
	reverse_rotate_list(lst2);
	write(1, "rrr\n", 4);
	return (1);
}
