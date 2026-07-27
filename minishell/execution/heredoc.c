/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:56:19 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/18 19:41:21 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <errno.h>

static void	write_heredoc_line(int pipefd, char *line, int skip_expand,
		t_mini *mini)
{
	char	*expanded;

	if (skip_expand)
		expanded = line;
	else
		expanded = expand_string(line, mini);
	write(pipefd, expanded, ft_strlen(expanded));
	write(pipefd, "\n", 1);
	if (!skip_expand)
		free(expanded);
}

static int	heredoc_write_loop(int pipefd, t_redir *redir, t_mini *mini)
{
	char	*line;

	if (!redir || !redir->file)
		return (0);
	line = readline("> ");
	while (line)
	{
		if (g_flag_sig == SIGINT || ft_strcmp(line, redir->file) == 0)
		{
			free(line);
			break ;
		}
		write_heredoc_line(pipefd, line, redir->quote_type != NONE, mini);
		free(line);
		line = readline("> ");
	}
	if (!line && g_flag_sig != SIGINT)
	{
		ft_putstr_fd("minishell: warning: here-document ", 2);
		ft_putstr_fd("delimited by end-of-file (wanted `", 2);
		ft_putstr_fd(redir->file, 2);
		ft_putendl_fd("')", 2);
	}
	return (0);
}

static void	heredoc_child(t_mini *mini, int pipefd[2], t_redir *redir)
{
	signal(SIGINT, heredoc_sigint_handler);
	signal(SIGQUIT, SIG_DFL);
	close_heredoc_fds(mini);
	close(mini->saved_stdout);
	close(pipefd[0]);
	dup2(mini->saved_stdin, STDIN_FILENO);
	close(mini->saved_stdin);
	heredoc_write_loop(pipefd[1], redir, mini);
	free_tokens(mini->tokens);
	free_commands(mini->head);
	free_env(mini->env);
	close(pipefd[1]);
	if (g_flag_sig == SIGINT)
		exit(128 + SIGINT);
	exit(0);
}

static int	heredoc_parent(int pipefd[2], pid_t pid, t_redir *redir,
		t_mini *mini)
{
	int	status;

	while (waitpid(pid, &status, 0) == -1)
	{
		if (errno == EINTR)
			continue ;
		close(pipefd[0]);
		return (-1);
	}
	if (WIFSIGNALED(status) || WEXITSTATUS(status) == 130)
	{
		if (WIFSIGNALED(status))
			mini->exit_status = 128 + WTERMSIG(status);
		else
			mini->exit_status = 130;
		close(pipefd[0]);
		g_flag_sig = 0;
		return (-1);
	}
	redir->heredoc_fd = pipefd[0];
	g_flag_sig = 0;
	return (0);
}

int	handle_heredoc(t_redir *redir, t_mini *mini)
{
	int		pipefd[2];
	pid_t	pid;
	void	(*old_sigint)(int);

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	old_sigint = signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == -1)
	{
		signal(SIGINT, old_sigint);
		perror("fork");
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	if (pid == 0)
		heredoc_child(mini, pipefd, redir);
	close(pipefd[1]);
	signal(SIGINT, old_sigint);
	return (heredoc_parent(pipefd, pid, redir, mini));
}
