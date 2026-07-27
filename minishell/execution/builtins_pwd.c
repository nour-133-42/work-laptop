/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 00:00:00 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/18 13:36:22 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd_function(char **env)
{
	char	buf[4096];
	char	*pwd;

	(void)env;
	if (getcwd(buf, 4096) != NULL)
	{
		printf("%s\n", buf);
		return ;
	}
	pwd = get_env_value(env, "PWD");
	if (pwd)
		printf("%s\n", pwd);
	else
		write(2, "minishell: pwd: error retrieving directory\n", 44);
}
