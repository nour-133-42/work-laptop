/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_and_lux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:11:45 by helfayez          #+#    #+#             */
/*   Updated: 2026/07/15 14:42:56 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	tok_helper(int i, t_token **tok, bool append, char *buf)
{
	if (buf[i] == '"')
		i = handle_double_quotes(buf, i, tok, append);
	else if (buf[i] == '\'')
		i = handle_single_quotes(buf, i, tok, append);
	if (i == -1)
	{
		ret_error();
		return (-1);
	}
	return (i);
}

static int	handle_pipe_token(char *buf, int i, t_token **tok)
{
	int		j;
	t_token	*new;

	if (i == 0)
	{
		ret_error();
		return (-1);
	}
	j = i + 1;
	while (buf[j] == ' ' || buf[j] == '\n' || buf[j] == '\t')
		j++;
	if (buf[j] == '\0' || buf[j] == '|')
	{
		ret_error();
		return (-1);
	}
	new = new_token_item("|", PIP, NONE);
	if (new)
		add_token(tok, new);
	return (i + 1);
}

static int	process_token(char *buf, int i, t_token **tok, bool append)
{
	if (buf[i] == '"' || buf[i] == '\'')
		i = tok_helper(i, tok, append, buf);
	else if (buf[i] == '|')
		i = handle_pipe_token(buf, i, tok);
	else if (buf[i] == '>' || buf[i] == '<')
		i = handle_op(buf, i, tok);
	else
		i = collect_word(buf, i, tok, append);
	return (i);
}

t_token	*tokenize(char *buf)
{
	t_token	*tok;
	int		i;
	bool	append;

	tok = NULL;
	i = 0;
	while (buf[i])
	{
		while (buf[i] == ' ' || buf[i] == '\n' || buf[i] == '\t')
			i++;
		if (!buf[i])
			break ;
		append = (i > 0 && buf[i - 1] != ' ' && buf[i - 1] != '\n' && buf[i
				- 1] != '\t');
		i = process_token(buf, i, &tok, append);
		if (i == -1)
		{
			free_tokens(tok);
			return (NULL);
		}
	}
	return (tok);
}

int	collect_word(char *buf, int i, t_token **tok, bool append)
{
	int		start;
	char	*word;
	t_token	*new;

	start = i;
	while (buf[i] && !special(buf[i]))
		i++;
	if (i == start)
		return (i);
	word = ft_substr(buf, start, i - start);
	if (!word)
		return (i);
	if (append)
	{
		append_or_create(tok, word, NONE);
		return (i);
	}
	new = new_token_item(word, WORD, NONE);
	if (new)
		add_token(tok, new);
	free(word);
	return (i);
}
