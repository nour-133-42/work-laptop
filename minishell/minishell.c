/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:46:24 by nour_133          #+#    #+#             */
/*   Updated: 2026/07/19 16:50:48 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_shell(t_mini *mini, char **env)
{
	mini->env = duplicate_env(env);
	if (!mini->env)
		return (1);
	mini->current = NULL;
	mini->head = NULL;
	mini->tokens = NULL;
	mini->pids = NULL;
	mini->exit_status = 0;
	mini->should_exit = false;
	mini->saved_stdin = dup(STDIN_FILENO);
	mini->saved_stdout = dup(STDOUT_FILENO);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}

static void	process_tokens(t_mini *mini, t_token *tok)
{
	expand_tokens(tok, mini);
	if (!validate_tokens(tok))
	{
		ret_error();
		mini->exit_status = 2;
		return ;
	}
	mini->current = parse_tokens(tok);
	if (!mini->current)
		return ;
	mini->head = mini->current;
	mini->tokens = tok;
	execution(mini);
	if (dup2(mini->saved_stdin, STDIN_FILENO) == -1)
		perror("minishell: dup2");
	if (dup2(mini->saved_stdout, STDOUT_FILENO) == -1)
		perror("minishell: dup2");
	if (check_exit(mini))
		mini->should_exit = true;
	free_commands(mini->head);
	mini->current = NULL;
	mini->head = NULL;
}

static int	handle_input(t_mini *mini)
{
	mini->line = readline("minishell> ");
	if (g_flag_sig == SIGINT)
	{
		mini->exit_status = 128 + g_flag_sig;
		g_flag_sig = 0;
	}
	if (!mini->line)
	{
		printf("exit\n");
		return (0);
	}
	if (*mini->line)
		add_history(mini->line);
	return (1);
}

static void	shell_loop(t_mini *mini)
{
	t_token	*tok;

	while (1)
	{
		mini->should_exit = false;
		if (!handle_input(mini))
			break ;
		tok = tokenize(mini->line);
		if (!tok)
		{
			free(mini->line);
			continue ;
		}
		process_tokens(mini, tok);
		free_tokens(tok);
		free(mini->line);
		if (mini->should_exit)
			break ;
	}
}

int	main(int ac, char **av, char **env)
{
	t_mini	mini;

	if (ac != 1)
		return (0);
	(void)av;
	if (init_shell(&mini, env))
		return (1);
	shell_loop(&mini);
	close(mini.saved_stdin);
	close(mini.saved_stdout);
	free_env(mini.env);
	return (mini.exit_status);
}
