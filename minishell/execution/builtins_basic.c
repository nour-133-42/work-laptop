/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:36:58 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/19 19:10:23 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_valid_n_flag(char *str)
{
	int	i;

	if (str[0] != '-' || str[1] != 'n')
		return (0);
	i = 2;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	echo_function(char **args)
{
	int	i;
	int	no_newline;

	i = 1;
	no_newline = 0;
	while (args[i] && is_valid_n_flag(args[i]))
	{
		no_newline = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!no_newline)
		ft_putstr_fd("\n", 1);
}

void	env_function(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	exit_function(char **args, t_mini *mini)
{
	if (!args[1])
	{
		write(2, "exit\n", 5);
		return (mini->exit_status);
	}
	if (args[2])
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		return (-1);
	}
	if (!is_numeric(args[1]))
	{
		write(2, "exit\n", 5);
		write(2, "minishell: exit: ", 17);
		write(2, args[1], ft_strlen(args[1]));
		write(2, " numeric argument required\n", 27);
		return (2);
	}
	write(2, "exit\n", 5);
	return ((unsigned char)ft_atoi(args[1]));
}
