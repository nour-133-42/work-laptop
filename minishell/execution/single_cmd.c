/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:40:00 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/18 15:26:25 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <errno.h>

static int	wait_single_command(t_mini *mini, int pid)
{
	int	status;

	while (waitpid(pid, &status, 0) == -1)
	{
		if (errno == EINTR)
			continue ;
		mini->exit_status = 1;
		return (-1);
	}
	mini->exit_status = wait_status_to_exit_code(status);
	return (0);
}

static void	single_command_child(t_mini *mini)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	close(mini->saved_stdin);
	close(mini->saved_stdout);
	mini->exit_status = execut_shell_command(mini);
	free_tokens(mini->tokens);
	free_commands(mini->head);
	free_env(mini->env);
	exit(mini->exit_status);
}

static int	fork_single_command(t_mini *mini, int *pid)
{
	void	(*old_sigint)(int);

	old_sigint = signal(SIGINT, SIG_IGN);
	*pid = fork();
	if (*pid == -1)
	{
		signal(SIGINT, old_sigint);
		perror("fork");
		mini->exit_status = 1;
		return (-1);
	}
	if (*pid == 0)
		single_command_child(mini);
	if (wait_single_command(mini, *pid) == -1)
	{
		signal(SIGINT, old_sigint);
		return (-1);
	}
	signal(SIGINT, old_sigint);
	return (0);
}

int	execute_one_command(t_mini *mini, int *pid)
{
	if (redirection_handling(mini, mini->current) == -1)
		return (-1);
	if (is_builtin(mini->current->args[0]) == 1)
	{
		mini->exit_status = execut_shell_command(mini);
		if (mini->exit_status == -1)
			mini->exit_status = 1;
		if (mini->exit_status == 2)
			mini->should_exit = true;
		return (0);
	}
	return (fork_single_command(mini, pid));
}
