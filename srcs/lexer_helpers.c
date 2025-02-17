/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:31:51 by ysuliman          #+#    #+#             */
/*   Updated: 2025/02/12 18:57:17 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

t_token	*get_operator(const char *input, int *i)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->token = ft_chrdup(input[*i]);s
	if (input[*i] == '<')
		token->type = TOKEN_REDIR_IN;
	else if (input[*i] == '>')
		token->type = TOKEN_REDIR_OUT;
	else if (input[*i] == '|')
		token->type = TOKEN_PIPE;
	(*i)++;
	return (token);
}
