/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:22:25 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/02 16:17:56 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(long data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = data;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

int	ft_atoi(const char *nptr)
{
	long	r;
	int		s;

	s = 1;
	r = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			s *= -1;
		nptr++;
	}
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
			r = r * 10 + (*(nptr++) - '0');
		else
			return (r * s);
	}
	return (r * s);
}

t_list	*fill_list(int argc, char *argv[])
{
	t_list	*head;
	t_list	*temp;
	int		value;
	int		i;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		temp = ft_lstnew(value);
		if (!temp)
			return (NULL);
		ft_lstadd_back(&head, temp);
		i++;
	}
	return (head);
}

void	free_list(t_list *head)
{
	t_list	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
