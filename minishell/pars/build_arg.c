/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 21:45:06 by helfayez          #+#    #+#             */
/*   Updated: 2026/07/18 15:06:39 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_redirection(t_token *tmp)
{
	return (tmp->type == INFILE || tmp->type == OUTFILE || tmp->type == APPEND
		|| tmp->type == HEREDOC);
}

t_token	*skip_redirection(t_token *tmp)
{
	tmp = tmp->next;
	if (tmp)
		tmp = tmp->next;
	return (tmp);
}

int	count_args(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->type != PIP)
	{
		if (is_redirection(tokens))
		{
			tokens = skip_redirection(tokens);
			continue ;
		}
		if (tokens->type == WORD && tokens->value && tokens->value[0] != '\0')
			count++;
		tokens = tokens->next;
	}
	return (count);
}

void	fill_argv(char **argv, t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens && tokens->type != PIP)
	{
		if (is_redirection(tokens))
		{
			tokens = skip_redirection(tokens);
			continue ;
		}
		if (tokens->type == WORD && tokens->value && tokens->value[0] != '\0')
			argv[i++] = ft_strdup(tokens->value);
		tokens = tokens->next;
	}
	argv[i] = NULL;
}

char	**build_argv(t_token *tokens)
{
	char	**argv;
	int		count;

	count = count_args(tokens);
	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);
	fill_argv(argv, tokens);
	return (argv);
}
