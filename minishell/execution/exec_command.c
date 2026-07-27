/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:26:58 by nalshmai          #+#    #+#             */
/*   Updated: 2026/07/18 15:20:37 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_path_line(char **envp)
{
	int	i;
	int	temp;

	i = 0;
	while (envp[i])
	{
		temp = ft_strncmp("PATH=", envp[i], 5);
		if (!temp)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	**get_paths(char **envp)
{
	char	*paths_string;
	char	**res;

	paths_string = find_path_line(envp);
	if (!paths_string)
		return (NULL);
	res = ft_split(paths_string, ':');
	if (!res)
		return (NULL);
	return (res);
}

static int	exec_direct(char **args, char **envp, char **paths)
{
	if (ft_strchr(args[0], '/'))
	{
		execve(args[0], args, envp);
		if (errno == ENOENT)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(args[0], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			free_all(paths, NULL, 0);
			return (127);
		}
		if (access(args[0], X_OK) == 0)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(args[0], 2);
			ft_putstr_fd(": Is a directory\n", 2);
			free_all(paths, NULL, 0);
			return (126);
		}
		perror("minishell");
		free_all(paths, NULL, 0);
		return (126);
	}
	return (0);
}

int	search_path(char **paths, char **args, char **envp)
{
	int		i;
	char	*tmp;
	char	*cmd;

	i = 0;
	while (paths && paths[i])
	{
		tmp = ft_strjoin(paths[i++], "/");
		if (!tmp)
			break ;
		cmd = ft_strjoin(tmp, args[0]);
		free(tmp);
		if (!cmd)
			break ;
		if (access(cmd, X_OK) == 0)
		{
			execve(cmd, args, envp);
			perror("minishell");
			free(cmd);
			free_all(paths, NULL, 0);
			return (126);
		}
		free(cmd);
	}
	return (0);
}

int	exec_command(char **paths, char **args, char **envp, int flag)
{
	int	ret;

	(void)flag;
	if (!args)
	{
		free_all(paths, NULL, 0);
		return (127);
	}
	ret = exec_direct(args, envp, paths);
	if (ret)
		return (ret);
	if (search_path(paths, args, envp))
		return (126);
	write(2, "minishell: command not found\n", 29);
	free_all(paths, NULL, 0);
	return (127);
}
