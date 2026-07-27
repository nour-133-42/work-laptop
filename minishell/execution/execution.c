/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:59:24 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/18 12:22:16 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	wait_status_to_exit_code(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			write(1, "\n", 1);
		else if (WTERMSIG(status) == SIGQUIT)
			write(1, "Quit (core dumped)\n", 19);
		return (128 + WTERMSIG(status));
	}
	return (1);
}

int	free_all(char **arr, char *arg, int res)
{
	int	i;

	if (arg)
		free(arg);
	if (arr)
	{
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
	return (res);
}

int	count_cmds(t_cmd *cmd)
{
	int	count;

	count = 0;
	while (cmd)
	{
		count++;
		cmd = cmd->next;
	}
	return (count);
}

void	close_pipes(t_mini *mini, int num_pipes)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		close(mini->pfd[i][0]);
		close(mini->pfd[i][1]);
		i++;
	}
}

int	initialize_pipe(t_mini *mini, int num_pipes)
{
	int	i;

	i = 0;
	mini->pfd = malloc(sizeof(int) * 2 * num_pipes);
	if (!mini->pfd)
		return (-1);
	while (i < num_pipes)
	{
		if (pipe(mini->pfd[i]) == -1)
		{
			perror("pipe");
			while (i-- > 0)
			{
				close(mini->pfd[i][0]);
				close(mini->pfd[i][1]);
			}
			return (-1);
		}
		i++;
	}
	return (0);
}
