/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour_eldeen <nour_eldeen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:40:00 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/19 10:28:47 by nour_eldeen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env_value(char **env, char *key)
{
	int	i;
	int	len;

	len = ft_strlen(key);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], key, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

static char	*get_current_pwd(char **env)
{
	char	buf[4096];
	char	*pwd;

	pwd = get_env_value(env, "PWD");
	if (pwd)
		return (ft_strdup(pwd));
	if (getcwd(buf, 4096) != NULL)
		return (ft_strdup(buf));
	return (ft_strdup(""));
}

static char	*resolve_cd_target(char **env, char **args)
{
	char	*target;

	if (!args[1] || ft_strcmp(args[1], "~") == 0)
	{
		target = get_env_value(env, "HOME");
		if (!target)
			write(2, "minishell: cd: HOME not set\n", 29);
		return (target);
	}
	if (ft_strcmp(args[1], "-") == 0)
	{
		target = get_env_value(env, "OLDPWD");
		if (!target)
		{
			write(2, "minishell: cd: OLDPWD not set\n", 30);
			return (NULL);
		}
		write(1, target, ft_strlen(target));
		write(1, "\n", 1);
		return (target);
	}
	return (args[1]);
}

static int	do_chdir(char *target, char **env, char *oldpwd)
{
	char	newpwd[4096];

	if (chdir(target) == -1)
	{
		perror("minishell: cd");
		free(oldpwd);
		return (1);
	}
	if (getcwd(newpwd, 4096) == NULL)
	{
		free(oldpwd);
		return (1);
	}
	export_to_env(env, "OLDPWD", oldpwd);
	export_to_env(env, "PWD", ft_strdup(newpwd));
	free(oldpwd);
	return (0);
}

int	cd_function(char **env, char **args)
{
	char	*oldpwd;
	char	*target;

	if (args[1] && args[2])
	{
		write(2, "minishell: cd: too many arguments\n", 34);
		return (1);
	}
	oldpwd = get_current_pwd(env);
	target = resolve_cd_target(env, args);
	if (!target)
	{
		free(oldpwd);
		return (1);
	}
	return (do_chdir(target, env, oldpwd));
}
