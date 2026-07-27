/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:50:42 by helfayez          #+#    #+#             */
/*   Updated: 2026/07/19 18:54:17 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_cmd	*create_cmd(t_token *tokens)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = build_argv(tokens);
	cmd->redir = build_redirs(tokens);
	cmd->next = NULL;
	return (cmd);
}

static void	add_cmd_back(t_cmd **head, t_cmd **last, t_cmd *cmd)
{
	if (!*head)
		*head = cmd;
	else
		(*last)->next = cmd;
	*last = cmd;
}

static t_token	*skip_to_next_pipe(t_token *tokens)
{
	while (tokens && tokens->type != PIP)
		tokens = tokens->next;
	if (tokens && tokens->type == PIP)
		tokens = tokens->next;
	return (tokens);
}

t_cmd	*parse_tokens(t_token *tokens)
{
	t_cmd	*head;
	t_cmd	*last;
	t_cmd	*cmd;

	head = NULL;
	last = NULL;
	while (tokens)
	{
		cmd = create_cmd(tokens);
		if (!cmd)
		{
			free_commands(head);
			return (NULL);
		}
		add_cmd_back(&head, &last, cmd);
		tokens = skip_to_next_pipe(tokens);
	}
	return (head);
}

char	*handle_exit_status(int last_exit, char *result)
{
	char	*value;
	char	*tmp;

	value = ft_itoa(last_exit);
	tmp = ft_strjoin(result, value);
	free(result);
	free(value);
	return (tmp);
}
