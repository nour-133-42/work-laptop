/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 13:34:44 by helfayez          #+#    #+#             */
/*   Updated: 2026/07/18 18:40:38 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*mark_single_quote_value(char *value)
{
	char	*tmp;
	char	*marked;

	tmp = ft_strjoin("\x01", value);
	if (!tmp)
		return (NULL);
	marked = ft_strjoin(tmp, "\x02");
	free(tmp);
	return (marked);
}

t_token	*new_token_item(char *value, t_every type, t_quote_type quote_type)
{
	t_token	*tok;

	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	if (quote_type == SINGLE)
		tok->value = mark_single_quote_value(value);
	else
		tok->value = ft_strdup(value);
	if (!tok->value)
	{
		free(tok);
		return (NULL);
	}
	tok->type = type;
	tok->quote_type = quote_type;
	tok->next = NULL;
	return (tok);
}

int	handle_single_redirect(char *buf, int i, t_token **tok, t_every type)
{
	t_token	*new;

	if (!buf[i + 1] || buf[i + 1] == '\n' || buf[i + 1] == '<' || buf[i
			+ 1] == '>')
	{
		ret_error();
		return (-1);
	}
	if (type == INFILE)
		new = new_token_item("<", INFILE, NONE);
	else
		new = new_token_item(">", OUTFILE, NONE);
	if (new)
		add_token(tok, new);
	return (i + 1);
}

int	handle_double_redirect(char *buf, int i, t_token **tok, t_every type)
{
	t_token	*new;

	if (!buf[i + 2] || buf[i + 2] == '\n' || buf[i + 2] == '<' || buf[i
			+ 2] == '>')
	{
		ret_error();
		return (-1);
	}
	if (type == HEREDOC)
		new = new_token_item("<<", HEREDOC, NONE);
	else
		new = new_token_item(">>", APPEND, NONE);
	if (new)
		add_token(tok, new);
	return (i + 2);
}

int	handle_op(char *buf, int i, t_token **tok)
{
	if (buf[i] == '<' && buf[i + 1] == '<')
		return (handle_double_redirect(buf, i, tok, HEREDOC));
	else if (buf[i] == '>' && buf[i + 1] == '>')
		return (handle_double_redirect(buf, i, tok, APPEND));
	else if (buf[i] == '<')
		return (handle_single_redirect(buf, i, tok, INFILE));
	else if (buf[i] == '>')
		return (handle_single_redirect(buf, i, tok, OUTFILE));
	return (i + 1);
}
