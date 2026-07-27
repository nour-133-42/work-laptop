/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour_eldeen <nour_eldeen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:37:46 by nour_eldeen       #+#    #+#             */
/*   Updated: 2026/07/17 13:35:39 by nour_eldeen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	handle_infile(t_redir *r)
{
	int	infd;

	infd = open(r->file, O_RDONLY);
	if (infd == -1)
	{
		perror("open");
		return (-1);
	}
	if (dup2(infd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		close(infd);
		return (-1);
	}
	close(infd);
	return (0);
}

static int	handle_output(t_redir *r, int flags)
{
	int	outfd;

	outfd = open(r->file, flags, 0644);
	if (outfd == -1)
	{
		perror("open");
		return (-1);
	}
	if (dup2(outfd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		close(outfd);
		return (-1);
	}
	close(outfd);
	return (0);
}

static int	handle_heredoc_fd(t_redir *r)
{
	if (r->heredoc_fd == -1)
		return (-1);
	if (dup2(r->heredoc_fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		close(r->heredoc_fd);
		r->heredoc_fd = -1;
		return (-1);
	}
	close(r->heredoc_fd);
	r->heredoc_fd = -1;
	return (0);
}

int	redirection_handling(t_mini *mini, t_cmd *node)
{
	t_redir	*r;

	(void)mini;
	r = node->redir;
	while (r)
	{
		if (r->type == INFILE && handle_infile(r) == -1)
			return (-1);
		if (r->type == OUTFILE && handle_output(r,
				O_WRONLY | O_CREAT | O_TRUNC) == -1)
			return (-1);
		if (r->type == APPEND && handle_output(r,
				O_WRONLY | O_CREAT | O_APPEND) == -1)
			return (-1);
		if (r->type == HEREDOC && handle_heredoc_fd(r) == -1)
			return (-1);
		r = r->next;
	}
	return (0);
}
