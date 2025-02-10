/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:14:51 by ysuliman          #+#    #+#             */
/*   Updated: 2025/02/07 19:07:57 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	append_token(t_list **list, t_token *token)
{
	t_list	*new_node;

	new_node = ft_lstnew(token);
	ft_lstadd_back(list, new_node);
}

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

t_list	*lexer(char *input)
{
	int		i;
	t_list	*list;
	t_token	*token;

	token = malloc(sizeof(t_token));
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			token = TOKEN_SQUOTE;
		else if (input[i] == '\"')
			token = TOKEN_DQUOTE;
		else if (is_operator(input[i]))
			token = NULL; // appended to NULL until we have a suitable function
		else if (is_whitespace(input[i]))
			token = NULL; // appended to NULL until we have a suitable function
		else
			token = getword(input, &i);
		append_token(list, token);
		i++;
	}
	append_token(list, TOKEN_EOF);
	return (list);
}
