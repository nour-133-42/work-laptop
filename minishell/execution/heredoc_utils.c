/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 13:31:14 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/18 13:06:49 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	process_all_heredocs(t_mini *mini)
{
	t_cmd	*cmd;
	t_redir	*r;

	cmd = mini->current;
	while (cmd)
	{
		r = cmd->redir;
		while (r)
		{
			if (r->type == HEREDOC)
			{
				if (handle_heredoc(r, mini) == -1)
					return (-1);
			}
			r = r->next;
		}
		cmd = cmd->next;
	}
	return (0);
}

void	close_heredoc_fds(t_mini *mini)
{
	t_cmd	*cmd;
	t_redir	*r;

	cmd = mini->head;
	while (cmd)
	{
		r = cmd->redir;
		while (r)
		{
			if (r->type == HEREDOC && r->heredoc_fd != -1)
			{
				close(r->heredoc_fd);
				r->heredoc_fd = -1;
			}
			r = r->next;
		}
		cmd = cmd->next;
	}
}

void	heredoc_sigint_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	close(STDIN_FILENO);
	g_flag_sig = SIGINT;
}
