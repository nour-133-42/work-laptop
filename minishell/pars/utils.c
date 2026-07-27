/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 11:43:12 by helfayez          #+#    #+#             */
/*   Updated: 2026/07/19 19:13:05 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

volatile int	g_flag_sig = 0;

void	ret_error(void)
{
	write(1, "ERROR IN YOUR INPUT\n", 20);
}

int	special(char c)
{
	return (c == ' ' || c == '|' || c == '<' || c == '\n' || c == '>'
		|| c == '\t' || c == '\'' || c == '"');
}

void	sigint_handler(int sig)
{
	g_flag_sig = sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	free_commands(t_cmd *cmds)
{
	t_cmd	*tmp_cmd;
	t_redir	*tmp_redir;
	int		i;

	while (cmds)
	{
		tmp_cmd = cmds;
		cmds = cmds->next;
		if (tmp_cmd->args)
		{
			i = 0;
			while (tmp_cmd->args[i])
				free(tmp_cmd->args[i++]);
			free(tmp_cmd->args);
		}
		while (tmp_cmd->redir)
		{
			tmp_redir = tmp_cmd->redir;
			tmp_cmd->redir = tmp_cmd->redir->next;
			free(tmp_redir->file);
			free(tmp_redir);
		}
		free(tmp_cmd);
	}
}

int	validate_tokens(t_token *tok)
{
	while (tok)
	{
		if ((tok->type == INFILE || tok->type == OUTFILE || tok->type == APPEND
				|| tok->type == HEREDOC))
		{
			if (!tok->next)
				return (0);
			if (tok->next->type != WORD)
				return (0);
		}
		tok = tok->next;
	}
	return (1);
}
