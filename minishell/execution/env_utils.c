/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:37:12 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/15 18:35:39 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**duplicate_env(char **env)
{
	int		i;
	int		count;
	char	**copy;

	count = 0;
	while (env[count])
		count++;
	copy = ft_calloc(count + 64, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < count)
	{
		copy[i] = ft_strdup(env[i]);
		if (!copy[i])
		{
			free_all(copy, NULL, 0);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		free(env[i++]);
	free(env);
}

char	*extract_var_from_env(char *var, t_mini *mini)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(var);
	while (mini->env[i])
	{
		if (!ft_strncmp(mini->env[i], var, len) && mini->env[i][len] == '=')
			return (ft_strdup(mini->env[i] + len + 1));
		i++;
	}
	return (ft_strdup(""));
}
