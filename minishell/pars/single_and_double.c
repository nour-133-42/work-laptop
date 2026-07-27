/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_and_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2026/06/20 21:51:55 by helfayez          #+#    #+#             */
/*   Updated: 2026/07/02 09:47:09 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//token function
void	add_token(t_token **head, t_token *new)
{
	t_token	*tmp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

const char	*token_type_name(t_every type)
{
	if (type == WORD)
		return ("WORD");
	if (type == PIP)
		return ("PIP");
	if (type == INFILE)
		return ("INFILE");
	if (type == OUTFILE)
		return ("OUTFILE");
	if (type == APPEND)
		return ("APPEND");
	if (type == HEREDOC)
		return ("HEREDOC");
	return ("UNKNOWN");
}

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->next;
		free(tmp->value);
		free(tmp);
	}
}

int	handle_double_quotes(char *buf, int i, t_token **tok, bool append)
{
	int		start;
	char	*word;
	t_token	*new;

	start = ++i;
	while (buf[i] && buf[i] != '"')
		i++;
	if (!buf[i])
		return (-1);
	word = ft_substr(buf, start, i - start);
	if (!word)
		return (i);
	if (append)
		append_or_create(tok, word, DOUBLE);
	else
	{
		new = new_token_item(word, WORD, DOUBLE);
		if (new)
			add_token(tok, new);
		free(word);
	}
	return (i + 1);
}

int	handle_single_quotes(char *buf, int i, t_token **tok, bool append)
{
	int		start;
	char	*word;
	t_token	*new;
	int		len;

	start = ++i;
	while (buf[i] && buf[i] != '\'')
		i++;
	if (!buf[i])
		return (-1);
	len = i - start;
	word = ft_substr(buf, start, len);
	if (!word)
		return (i);
	if (append)
		append_or_create(tok, word, SINGLE);
	else
	{
		new = new_token_item(word, WORD, SINGLE);
		if (new)
			add_token(tok, new);
		free(word);
	}
	return (i + 1);
}
