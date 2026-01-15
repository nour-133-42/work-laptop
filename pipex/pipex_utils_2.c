/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:07 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/14 15:56:20 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			perror("pipex");
			return (free_all(args, cmd, 126));
		}
		free(cmd);
	}
	return (0);
}
