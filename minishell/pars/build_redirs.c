/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 21:47:44 by helfayez          #+#    #+#             */
/*   Updated: 2026/07/19 18:53:59 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// expand string function

char	*handle_env_var(char *str, int *i, t_mini *mini, char *result)
{
	int		start;
	char	*key;
	char	*value;
	char	*tmp;

	start = *i;
	if (ft_isdigit(str[*i]))
		(*i)++;
	else
	{
		while (ft_isalnum(str[*i]) || str[*i] == '_')
			(*i)++;
	}
	key = ft_substr(str, start, *i - start);
	value = extract_var_from_env(key, mini);
	tmp = ft_strjoin(result, value);
	free(result);
	free(key);
	free(value);
	return (tmp);
}

static char	*strip_quote_markers(char *value)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	if (!value)
		return (NULL);
	len = ft_strlen(value);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (value[i])
	{
		if (value[i] != '\x01' && value[i] != '\x02')
			result[j++] = value[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}

t_redir	*new_redir_node(t_token *tmp)
{
	t_redir	*new_redir;
	char	*stripped;

	if (!tmp->next || tmp->next->type != WORD)
		return (NULL);
	new_redir = malloc(sizeof(t_redir));
	if (!new_redir)
		return (NULL);
	new_redir->type = tmp->type;
	if (tmp->next->quote_type == SINGLE)
	{
		stripped = strip_quote_markers(tmp->next->value);
		new_redir->file = stripped;
	}
	else
		new_redir->file = ft_strdup(tmp->next->value);
	new_redir->quote_type = tmp->next->quote_type;
	new_redir->heredoc_fd = -1;
	if (!new_redir->file)
	{
		free(new_redir);
		return (NULL);
	}
	new_redir->next = NULL;
	return (new_redir);
}

void	add_redir(t_redir **redirs, t_redir **last, t_redir *new_redir)
{
	if (!*redirs)
		*redirs = new_redir;
	else
		(*last)->next = new_redir;
	*last = new_redir;
}

t_redir	*build_redirs(t_token *tokens)
{
	t_redir	*redirs;
	t_redir	*last;
	t_redir	*new_redir;

	redirs = NULL;
	last = NULL;
	while (tokens && tokens->type != PIP)
	{
		if (tokens->type == INFILE || tokens->type == OUTFILE
			|| tokens->type == APPEND || tokens->type == HEREDOC)
		{
			new_redir = new_redir_node(tokens);
			if (!new_redir)
				return (NULL);
			add_redir(&redirs, &last, new_redir);
			tokens = tokens->next;
		}
		tokens = tokens->next;
	}
	return (redirs);
}
