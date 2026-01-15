/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:28:18 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/14 15:56:54 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static char	**get_args(char **argv, int flag)
{
	char	**args;

	if (flag == 1)
	{
		args = ft_split(argv[2], ' ');
	}
	else
		args = ft_split(argv[3], ' ');
	if (!args || !args[0])
	{
		write(2, "pipex: command not found\n", 25);
		free_all(args, NULL, 0);
		return (NULL);
	}
	return (args);
}

static int	exec_direct(char **args, char **envp, char **paths)
{
	if (ft_strchr(args[0], '/'))
	{
		execve(args[0], args, envp);
		perror("pipex");
		free_all(paths, NULL, 0);
		return (free_all(args, NULL, 126));
	}
	return (0);
}

int	exec_command(char **paths, char **argv, char **envp, int flag)
{
	char	**args;

	args = get_args(argv, flag);
	if (!args)
	{
		free_all(paths, NULL, 0);
		return (127);
	}
	if (exec_direct(args, envp, paths))
		return (126);
	if (search_path(paths, args, envp))
		return (126);
	write(2, "pipex: command not found\n", 25);
	free_all(paths, NULL, 0);
	return (free_all(args, NULL, 127));
}

void	ending(int *pid)
{
	int	retstat;
	int	status;
	int	exitstat;

	exitstat = 0;
	while (1)
	{
		retstat = wait(&status);
		if (retstat == -1)
			break ;
		if (pid[1] == retstat)
			exitstat = status;
	}
	if (WIFEXITED(exitstat))
		exit(WEXITSTATUS(exitstat));
	exit(1);
}
