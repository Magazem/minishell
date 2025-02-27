/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   body_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-27 17:12:07 by ysuliman          #+#    #+#             */
/*   Updated: 2025-02-27 17:12:07 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	parse_modifiers(t_list **tokens)
{
	(void)tokens;
	return (0);
}

t_command	*parse_pipeline(t_list **tokens)
{
	t_command	*head;
	t_command	*current;
	t_token		*pipe_token;
	t_command	*next_command;

	head = parse_command(tokens);
	current = head;
	while (tokens && *tokens && peek(*tokens) == TOKEN_PIPE)
	{
		pipe_token = consume_token(tokens);
		if (!pipe_token)
		{
			fprintf(stderr, "error: failed to consume pipe token.\n");
			return (NULL);
		}
		free(pipe_token);
		next_command = parse_command(tokens);
		if (!next_command)
		{
			fprintf(stderr,
				"error: failed to parse next command in pipeline.\n");
			return (NULL);
		}
		current->next = next_command;
		current = current->next;
	}
	return (head);
}

t_ast	*parse_body(t_list **tokens)
{
	t_ast		*ast;
	t_command	*pipeline;
	int			background;

	if (!tokens || !*tokens)
	{
		fprintf(stderr, "error: empty command line.\n");
		return (NULL);
	}
	ast = malloc(sizeof(t_ast));
	if (!ast)
	{
		perror("malloc");
		return (NULL);
	}
	pipeline = parse_pipeline(tokens);
	if (!pipeline)
	{
		fprintf(stderr, "error: failed to parse the command pipeline.\n");
		free(ast);
		return (NULL);
	}
	ast->pipeline = pipeline;
	background = parse_modifiers(tokens);
	ast->background = background;
	if (tokens && *tokens && peek(*tokens) != TOKEN_EOF)
	{
		fprintf(stderr, "error: unexpected token after command.\n");
		free(ast);
		return (NULL);
	}
	return (ast);
}
