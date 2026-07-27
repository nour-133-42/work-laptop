/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 13:31:14 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/18 14:42:25 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_one_cmd(t_mini *mini)
{
	int	pid;

	if (execute_one_command(mini, &pid) == -1 && mini->exit_status == 0)
		mini->exit_status = 1;
}

void	execute_pipeline_cmds(t_mini *mini, int num_cmds_total)
{
	t_cmd	*original;

	mini->pids = malloc(sizeof(int) * num_cmds_total);
	if (!mini->pids)
	{
		mini->exit_status = 1;
		return ;
	}
	original = mini->current;
	pipeline_executor(mini, mini->pids, num_cmds_total);
	mini->current = original;
	free(mini->pids);
	mini->pids = NULL;
}
