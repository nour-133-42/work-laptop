/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_flow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:37:23 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/18 14:42:34 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <errno.h>

static int	pipeline_error(t_mini *mini, void (*old)(int), int num_pipes)
{
	signal(SIGINT, old);
	if (num_pipes > 0)
	{
		close_pipes(mini, num_pipes);
		free(mini->pfd);
	}
	mini->exit_status = 1;
	return (-1);
}

static int	wait_and_restore(t_mini *mini, int *pid, int num_cmds_total,
		void (*old)(int))
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < num_cmds_total)
	{
		if (waitpid(pid[i], &status, 0) == -1)
		{
			if (errno == EINTR)
				continue ;
			mini->exit_status = 1;
			signal(SIGINT, old);
			return (-1);
		}
		i++;
	}
	mini->exit_status = wait_status_to_exit_code(status);
	signal(SIGINT, old);
	return (0);
}

static int	run_middle_commands(t_mini *mini, t_cmd **cursor, int *pid)
{
	int	i;

	i = 1;
	while ((*cursor)->next)
	{
		mini->current = *cursor;
		if (execute_middle_command(mini, &pid[i], i) == -1)
			return (-1);
		i++;
		*cursor = (*cursor)->next;
	}
	return (i);
}

int	pipeline_executor(t_mini *mini, int *pid, int num_cmds_total)
{
	t_cmd	*cursor;
	void	(*old)(int);
	int		i;

	old = signal(SIGINT, SIG_IGN);
	cursor = mini->current;
	mini->pipe_count = num_cmds_total - 1;
	if (initialize_pipe(mini, mini->pipe_count) == -1)
		return (pipeline_error(mini, old, 0));
	if (execute_first_command(mini, &pid[0]) == -1)
		return (pipeline_error(mini, old, mini->pipe_count));
	cursor = cursor->next;
	i = run_middle_commands(mini, &cursor, pid);
	if (i == -1)
		return (pipeline_error(mini, old, mini->pipe_count));
	mini->current = cursor;
	if (execute_last_command(mini, &pid[i], mini->pipe_count - 1) == -1)
		return (pipeline_error(mini, old, mini->pipe_count));
	close_pipes(mini, num_cmds_total - 1);
	free(mini->pfd);
	return (wait_and_restore(mini, pid, num_cmds_total, old));
}

void	execution(t_mini *mini)
{
	int	num_cmds_total;

	num_cmds_total = count_cmds(mini->current);
	if (num_cmds_total == 0)
		return ;
	if (process_all_heredocs(mini) == -1)
	{
		close_heredoc_fds(mini);
		return ;
	}
	if (num_cmds_total == 1)
		execute_one_cmd(mini);
	else
		execute_pipeline_cmds(mini, num_cmds_total);
	close_heredoc_fds(mini);
}
