/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 11:29:26 by helfayez          #+#    #+#             */
/*   Updated: 2026/07/15 18:32:47 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	append_or_create_helper(t_token **tok, char *s, t_quote_type quote_type)
{
	t_token	*new;

	new = new_token_item(s, WORD, quote_type);
	if (new)
		add_token(tok, new);
	free(s);
}

static char	*mark_single_quote(char *s, t_quote_type quote_type)
{
	char	*tmp;
	char	*marked;

	if (quote_type != SINGLE)
		return (s);
	tmp = ft_strjoin("\x01", s);
	if (!tmp)
		return (s);
	marked = ft_strjoin(tmp, "\x02");
	free(tmp);
	if (!marked)
		return (s);
	return (marked);
}

static void	update_token_value(t_token *last, char *joined,
		t_quote_type quote_type)
{
	free(last->value);
	last->value = joined;
	if (last->quote_type != quote_type)
		last->quote_type = NONE;
}

static t_token	*get_last_token(t_token *tok)
{
	while (tok->next)
		tok = tok->next;
	return (tok);
}

void	append_or_create(t_token **tok, char *s, t_quote_type quote_type)
{
	t_token	*last;
	char	*joined;
	char	*marked_s;

	if (!s)
		return ;
	if (!*tok)
		return (append_or_create_helper(tok, s, quote_type));
	last = get_last_token(*tok);
	if (last->type != WORD)
		return (append_or_create_helper(tok, s, quote_type));
	marked_s = mark_single_quote(s, quote_type);
	joined = ft_strjoin(last->value, marked_s);
	if (quote_type == SINGLE && marked_s != s)
		free(marked_s);
	if (joined)
		update_token_value(last, joined, quote_type);
	free(s);
}
