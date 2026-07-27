/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:50:27 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/14 16:37:26 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	child_one(t_pipex *pipex, char **argv, char **envp)
{
	int		infile;
	char	**paths;

	close(pipex->fd1[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		close(pipex->fd1[1]);
		perror("pipex");
		exit(1);
	}
	if (dup2(infile, STDIN_FILENO) < 0 || dup2(pipex->fd1[1],
			STDOUT_FILENO) < 0)
	{
		close(pipex->fd1[1]);
		close(infile);
		perror("pipex");
		exit(1);
	}
	close(pipex->fd1[1]);
	close(infile);
	paths = get_paths(envp);
	exit(exec_command(paths, argv, envp, 1));
}

void	child_two(t_pipex *pipex, char **argv, char **envp)
{
	int		outfile;
	char	**paths;

	close(pipex->fd1[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		close(pipex->fd1[0]);
		perror("pipex");
		exit(1);
	}
	if (dup2(pipex->fd1[0], STDIN_FILENO) < 0 || dup2(outfile,
			STDOUT_FILENO) < 0)
	{
		close(pipex->fd1[0]);
		close(outfile);
		perror("pipex");
		exit(1);
	}
	close(pipex->fd1[0]);
	close(outfile);
	paths = get_paths(envp);
	exit(exec_command(paths, argv, envp, 2));
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		pid[2];

	if (argc != 5)
	{
		write(2, "Error: Invalid number of arguments\n", 36);
		return (1);
	}
	if (pipe(pipex.fd1) == -1)
		return (1);
	if (create_children(&pipex, argv, envp, pid))
	{
		close(pipex.fd1[0]);
		close(pipex.fd1[1]);
		return (1);
	}
	close(pipex.fd1[0]);
	close(pipex.fd1[1]);
	ending(pid);
	return (0);
}
