/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 00:00:00 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/15 18:35:41 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	remove_env_entry(char **env, int idx)
{
	free(env[idx]);
	env[idx] = env[idx + 1];
	while (env[idx])
	{
		env[idx] = env[idx + 1];
		idx++;
	}
}

void	unset_function(char **args, char **env)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (env[j])
		{
			if (ft_strcmp(env[j], args[i]) == 0)
			{
				remove_env_entry(env, j);
				break ;
			}
			if (ft_strncmp(env[j], args[i], ft_strlen(args[i])) == 0
				&& env[j][ft_strlen(args[i])] == '=')
			{
				remove_env_entry(env, j);
				break ;
			}
			j++;
		}
		i++;
	}
}
