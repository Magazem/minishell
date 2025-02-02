/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:14:51 by ysuliman          #+#    #+#             */
/*   Updated: 2025/02/01 19:53:40 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_special_char(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '\'' || c == '\"'
		|| c == ' ' || c == '\t' || c == '\n');
}

char	*getword(char *line, int i)
{
	int		start;
	char	*word;

	start = i;
	while (line[i] && !isspeacial_character(word[i]))
		i++;
	word = ft_substr(line, start, i - start);
	return (word);
}

t_token	**lexer(char *input)
{
	int i;
	t_token **tokens;
	// Initialize token list, index i, etc.
	while (input[i])
	{
		if (input[i] == '\'')
			*get_singlequoted(input, &i);
		else if (input[i] == '\"')
			get_doublequoted(input, &i);
		else if (is_operator(input[i]))
		{
			// Handle token operators accordingly.
		}
		else if (is_whitespace(input[i]))
		{
			i++;
		}
		else
		{
			getword(input, &i);
		}
	}
	// Append TOKEN_EOF at the end.
	return (tokens);
}