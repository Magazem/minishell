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

t_token	*get_token(char input, int *i)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->token = &input;
	if (input == '\'')
		token->type = TOKEN_SQUOTE;
	else if (input == '\"')
		token->type = TOKEN_DQUOTE;
	else if (input == '\0')
		token->type = TOKEN_EOF;
	else if (input == ' ')
		token->type = TOKEN_SPACE;
	(*i)++;
	return (token);
}

void	append_token(t_list **list, t_token *token)
{
	t_list	*new_node;

	new_node = ft_lstnew(token);
	ft_lstadd_back(list, new_node);
}

int	is_special_char(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '\'' || c == '\"'
		|| c == ' ');
}

t_token	*getword(char *line, int *i)
{
	int		start;
	t_token	*word;

	word = malloc(sizeof(t_token));
	if (!word)
		return (NULL);
	start = *i;
	while (line[*i] && !is_special_char(line[*i]))
		(*i)++;
	word->token = ft_substr(line, start, *i - start);
	word->type = TOKEN_WORD;
	return (word);
}

t_list	*lexer(char *input)
{
	int		i;
	int		count;
	t_list	*list;
	t_token	*token;

	i = 0;
	count = 0;
	list = NULL;
	while (input[i])
	{
		if (input[i] == '\'')
			token = get_token('\'', &i);
		else if (input[i] == '\"')
			token = get_token('\"', &i);
		else if (is_operator(input[i]))
			token = get_operator(&input[i], &i);
		else if (input[i] == ' ')
			token = get_token(' ', &i);
		else
			token = getword(input, &i);
		append_token(&list, token);
	}
	append_token(&list, get_token('\0', &i));
	return (list);
}
