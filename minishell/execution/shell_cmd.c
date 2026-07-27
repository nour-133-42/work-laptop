/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:40:00 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/19 18:48:06 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char *command)
{
	if (!command)
		return (-1);
	if (ft_strcmp(command, "echo") == 0 || ft_strcmp(command, "cd") == 0
		|| ft_strcmp(command, "export") == 0 || ft_strcmp(command, "unset") == 0
		|| ft_strcmp(command, "env") == 0 || ft_strcmp(command, "exit") == 0
		|| ft_strcmp(command, "pwd") == 0)
		return (1);
	return (0);
}

static int	handle_command_paths(t_mini *mini)
{
	char	**paths;

	paths = get_paths(mini->env);
	if (!paths)
	{
		write(2, "minishell: PATH not found\n", 27);
		return (127);
	}
	return (exec_command(paths, mini->current->args, mini->env, 0));
}

static int	handle_shell_builtin(t_mini *mini, char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		echo_function(mini->current->args);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (cd_function(mini->env, mini->current->args));
	else if (ft_strcmp(cmd, "export") == 0)
		return (export_function(mini->current, mini->env));
	else if (ft_strcmp(cmd, "unset") == 0)
		unset_function(mini->current->args, mini->env);
	else if (ft_strcmp(cmd, "env") == 0)
		env_function(mini->env);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (exit_function(mini->current->args, mini));
	else if (ft_strcmp(cmd, "pwd") == 0)
		pwd_function(mini->env);
	else
		return (handle_command_paths(mini));
	return (0);
}

int	execut_shell_command(t_mini *mini)
{
	char	*cmd;

	cmd = NULL;
	if (mini->current && mini->current->args)
		cmd = mini->current->args[0];
	if (!cmd)
		return (0);
	else
		return (handle_shell_builtin(mini, cmd));
	return (0);
}
