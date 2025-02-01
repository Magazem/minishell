/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-31 16:14:51 by ysuliman          #+#    #+#             */
/*   Updated: 2025-01-31 16:14:51 by ysuliman         ###   ########.fr       */
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

void	lexer(char *line)
{
}