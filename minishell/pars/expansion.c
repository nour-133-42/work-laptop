/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:01:44 by helfayez          #+#    #+#             */
/*   Updated: 2026/07/15 14:42:03 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*handle_dollar_fallback(char *result)
{
	char	*tmp;

	tmp = ft_strjoin(result, "$");
	free(result);
	return (tmp);
}

char	*handle_dollar_case(char *str, int *i, t_mini *mini, char **result)
{
	(*i)++;
	if (str[*i] == '?')
	{
		*result = handle_exit_status(mini->exit_status, *result);
		(*i)++;
	}
	else if (ft_isalnum(str[*i]) || str[*i] == '_')
		*result = handle_env_var(str, i, mini, *result);
	else
		*result = handle_dollar_fallback(*result);
	return (*result);
}

char	*append_normal_char(char *str, int *i, char *result)
{
	char	tmp_char[2];
	char	*tmp;

	tmp_char[0] = str[*i];
	tmp_char[1] = '\0';
	tmp = ft_strjoin(result, tmp_char);
	free(result);
	(*i)++;
	return (tmp);
}

char	*expand_string_with_quotes(char *str, t_mini *mini,
		int *quote_positions)
{
	int		i;
	char	*result;

	i = 0;
	result = ft_strdup("");
	while (str[i])
	{
		if (quote_positions && quote_positions[i])
		{
			result = append_normal_char(str, &i, result);
		}
		else if (str[i] == '$')
			result = handle_dollar_case(str, &i, mini, &result);
		else
			result = append_normal_char(str, &i, result);
	}
	return (result);
}

char	*expand_string(char *str, t_mini *mini)
{
	int		i;
	char	*result;
	int		in_single_quote;

	i = 0;
	in_single_quote = 0;
	result = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '\x01')
		{
			in_single_quote = 1;
			i++;
		}
		else if (str[i] == '\x02')
		{
			in_single_quote = 0;
			i++;
		}
		else if (str[i] == '$' && !in_single_quote)
			result = handle_dollar_case(str, &i, mini, &result);
		else
			result = append_normal_char(str, &i, result);
	}
	return (result);
}
