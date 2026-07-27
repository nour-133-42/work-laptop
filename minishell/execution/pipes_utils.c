/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 09:40:00 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/19 09:40:00 by nour_eldeen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	child_cleanup(t_mini *mini)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	free_commands(mini->head);
	free_tokens(mini->tokens);
	free_env(mini->env);
	free(mini->line);
	free(mini->pfd);
	free(mini->pids);
}

void	setup_and_exec(t_mini *mini)
{
	close_pipes(mini, mini->pipe_count);
	if (redirection_handling(mini, mini->current) == -1)
	{
		child_cleanup(mini);
		exit(1);
	}
	close_heredoc_fds(mini);
	mini->exit_status = execut_shell_command(mini);
	child_cleanup(mini);
	exit(mini->exit_status);
}
