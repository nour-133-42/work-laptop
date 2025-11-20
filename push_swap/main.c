/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:22:23 by nalshmai          #+#    #+#             */
/*   Updated: 2025/11/16 16:34:01 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	t_list	*temp;
	int		i;

	i = 0;
	a = fill_list(argc, argv);
	b = NULL;
	if (!a)
		return (NULL);
	// temp = a;
	while (a->next->next->next->next != NULL)
		i += pb(&a, &b);
	if (!if_sorted_1(a))
		i += sa(&a);
	while (b)
	{
		execute_operations(&a, &b);
	}
}
