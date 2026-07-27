/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:01:00 by nalshmai         #+#    #+#             */
/*   Updated: 2026/07/19 17:01:00 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	split_expanded_token(t_token **tmp, t_token **prev)
{
	char	**words;
	int		i;
	t_token	*next_orig;
	t_token	*new_node;

	words = ft_split((*tmp)->value, ' ');
	if (!words || !words[0])
		return ;
	next_orig = (*tmp)->next;
	free((*tmp)->value);
	(*tmp)->value = ft_strdup(words[0]);
	i = 1;
	while (words[i])
	{
		new_node = new_token_item(words[i], WORD, NONE);
		if (!new_node)
			break ;
		(*tmp)->next = new_node;
		*tmp = new_node;
		i++;
	}
	(*tmp)->next = next_orig;
	free_all(words, NULL, 0);
	*prev = *tmp;
	*tmp = (*tmp)->next;
}

static int	expand_one_token(t_token **tmp, t_token **prev, t_mini *mini)
{
	char	*expanded;
	int		had_dollar;

	had_dollar = ft_strchr((*tmp)->value, '$') != NULL;
	expanded = expand_string((*tmp)->value, mini);
	free((*tmp)->value);
	(*tmp)->value = expanded;
	if (had_dollar && (*tmp)->quote_type == NONE
		&& ft_strchr((*tmp)->value, ' '))
	{
		split_expanded_token(tmp, prev);
		return (1);
	}
	return (0);
}

void	expand_tokens(t_token *tok, t_mini *mini)
{
	t_token	*tmp;
	t_token	*prev;

	tmp = tok;
	prev = NULL;
	while (tmp)
	{
		if (tmp->type == WORD && tmp->quote_type != SINGLE
			&& (!prev || prev->type != HEREDOC))
		{
			if (expand_one_token(&tmp, &prev, mini))
				continue ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

int	check_exit(t_mini *mini)
{
	if (!mini->current || !mini->current->args
		|| !mini->current->args[0])
		return (0);
	if (ft_strcmp(mini->current->args[0], "exit") != 0)
		return (0);
	if (mini->current->next)
		return (0);
	if (mini->current->args[1]
		&& (!is_numeric(mini->current->args[1])
			|| mini->current->args[2]))
		return (0);
	return (1);
}
