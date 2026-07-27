/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:37:39 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/19 09:40:00 by nour_eldeen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	last_command_child(t_mini *mini, int last_pipe_index)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	close(mini->saved_stdin);
	close(mini->saved_stdout);
	if (dup2(mini->pfd[last_pipe_index][0], STDIN_FILENO) < 0)
	{
		perror("dup2");
		child_cleanup(mini);
		exit(1);
	}
	setup_and_exec(mini);
}

int	execute_first_command(t_mini *mini, int *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		mini->exit_status = 1;
		return (-1);
	}
	if (*pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		close(mini->saved_stdin);
		close(mini->saved_stdout);
		if (dup2(mini->pfd[0][1], STDOUT_FILENO) < 0)
		{
			perror("dup2");
			child_cleanup(mini);
			exit(1);
		}
		setup_and_exec(mini);
	}
	return (0);
}

static void	middle_command_child(t_mini *mini, int i)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	close(mini->saved_stdin);
	close(mini->saved_stdout);
	if (dup2(mini->pfd[i - 1][0], STDIN_FILENO) < 0)
	{
		perror("dup2");
		child_cleanup(mini);
		exit(1);
	}
	if (dup2(mini->pfd[i][1], STDOUT_FILENO) < 0)
	{
		perror("dup2");
		child_cleanup(mini);
		exit(1);
	}
	setup_and_exec(mini);
}

int	execute_middle_command(t_mini *mini, int *pid, int i)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		mini->exit_status = 1;
		return (-1);
	}
	if (*pid == 0)
		middle_command_child(mini, i);
	return (0);
}

int	execute_last_command(t_mini *mini, int *pid, int last_pipe_index)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		mini->exit_status = 1;
		return (-1);
	}
	if (*pid == 0)
		last_command_child(mini, last_pipe_index);
	return (0);
}
