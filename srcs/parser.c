/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-24 12:48:49 by ysuliman          #+#    #+#             */
/*   Updated: 2025-02-24 12:48:49 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_command	*parse_command_name(t_list **tokens)
{
	t_command	*cmd;
	t_token		*token;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
	{
		perror("malloc");
		return (NULL);
	}
	cmd->args = NULL;
	cmd->input_file = NULL;
	cmd->output_file = NULL;
	cmd->next = NULL;
	token = consume_token(tokens);
	if (!token || token->type != TOKEN_WORD)
	{
		fprintf(stderr, "error: command name or options expected.\n");
		free(cmd);
		return (NULL);
	}
	cmd->args = add_argument(cmd->args, token->token);
	return (cmd);
}

static int	parse_redirection(t_list **tokens, t_command *cmd)
{
	t_token	*token;

	token = consume_token(tokens);
	if (token->type == TOKEN_REDIR_IN)
	{
		token = consume_token(tokens);
		if (!token || token->type != TOKEN_WORD)
		{
			fprintf(stderr, "error: filename expected after <.\n");
			return (0);
		}
		cmd->input_file = token->token;
	}
	else if (token->type == TOKEN_REDIR_OUT)
	{
		token = consume_token(tokens);
		if (!token || token->type != TOKEN_WORD)
		{
			fprintf(stderr, "error: filename expected after >.\n");
			return (0);
		}
		cmd->output_file = token->token;
	}
	return (1);
}

static int	parse_arguments(t_list **tokens, t_command *cmd)
{
	t_token	*token;

	token = consume_token(tokens);
	if (!token || token->type != TOKEN_WORD)
		return (0);
	cmd->args = add_argument(cmd->args, token->token);
	return (1);
}

t_command	*parse_command(t_list **tokens)
{
	t_command	*cmd;

	cmd = parse_command_name(tokens);
	if (!cmd)
		return (NULL);
	while (*tokens != NULL && peek(*tokens) != TOKEN_PIPE
		&& peek(*tokens) != TOKEN_EOF)
	{
		if (peek(*tokens) == TOKEN_REDIR_IN || peek(*tokens) == TOKEN_REDIR_OUT)
		{
			if (!parse_redirection(tokens, cmd))
				return (NULL);
		}
		else if (peek(*tokens) == TOKEN_WORD)
		{
			if (!parse_arguments(tokens, cmd))
				return (NULL);
		}
		else
		{
			fprintf(stderr, "error: unexpected token.\n");
			return (NULL);
		}
	}
	return (cmd);
}
