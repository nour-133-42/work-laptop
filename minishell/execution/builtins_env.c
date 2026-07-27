/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:37:06 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/15 18:35:45 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_to_env(char **env, char *key, char *value)
{
	int		i;
	int		key_len;
	char	*new_entry;
	char	*tmp;

	key_len = ft_strlen(key);
	tmp = ft_strjoin(key, "=");
	new_entry = ft_strjoin(tmp, value);
	free(tmp);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], key, key_len) == 0
			&& (env[i][key_len] == '=' || env[i][key_len] == '\0'))
		{
			free(env[i]);
			env[i] = new_entry;
			return ;
		}
		i++;
	}
	env[i] = new_entry;
	env[i + 1] = NULL;
}

static int	is_valid_export_id(char *str)
{
	int	i;

	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	handle_export_no_equals(char **env, char *arg)
{
	int	env_len;

	if (!is_valid_export_id(arg))
	{
		write(2, "minishell: export: `", 20);
		write(2, arg, ft_strlen(arg));
		write(2, "': not a valid identifier\n", 26);
		return (1);
	}
	env_len = 0;
	while (env[env_len])
	{
		if (ft_strcmp(env[env_len], arg) == 0)
			return (0);
		if (ft_strncmp(env[env_len], arg, ft_strlen(arg)) == 0
			&& env[env_len][ft_strlen(arg)] == '=')
			return (0);
		env_len++;
	}
	env[env_len] = ft_strdup(arg);
	env[env_len + 1] = NULL;
	return (0);
}

static int	handle_export_arg(char **env, char *arg)
{
	char	*equals;
	char	*key;

	equals = ft_strchr(arg, '=');
	if (equals)
	{
		key = ft_substr(arg, 0, equals - arg);
		if (!is_valid_export_id(key))
		{
			write(2, "minishell: export: `", 20);
			write(2, arg, ft_strlen(arg));
			write(2, "': not a valid identifier\n", 26);
			free(key);
			return (1);
		}
		export_to_env(env, key, equals + 1);
		free(key);
		return (0);
	}
	return (handle_export_no_equals(env, arg));
}

int	export_function(t_cmd *node, char **env)
{
	int	i;
	int	status;

	i = 1;
	status = 0;
	if (!node->args[i])
	{
		i = 0;
		while (env[i])
		{
			printf("declare -x %s\n", env[i]);
			i++;
		}
		return (0);
	}
	while (node->args[i])
	{
		if (handle_export_arg(env, node->args[i]))
			status = 1;
		i++;
	}
	return (status);
}
