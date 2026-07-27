/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:02:57 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/21 17:41:04 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && n)
	{
		if (*s1 != *s2)
		{
			break ;
		}
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	process_operation(char *line, t_list **a, t_list **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(b, a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	execute_checker_operations(t_list **a, t_list **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (if_sorted_2(*a) && *b == NULL)
			break ;
		if (!process_operation(line, a, b))
		{
			write(2, "Error\n", 6);
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc > 1)
	{
		if (!check_not_int(argv + 1) || !check_max_int(argc, argv)
			|| !check_dublicates(argc, argv))
			return (0);
		a = fill_list(argc, argv);
		b = NULL;
		if (execute_checker_operations(&a, &b))
		{
			if (if_sorted_2(a) && b == NULL)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		free_list(a);
	}
}
