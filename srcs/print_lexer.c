/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 17:13:49 by ysuliman          #+#    #+#             */
/*   Updated: 2025-02-10 17:13:49 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

const char	*token_type_to_str(t_token_type type)
{
	const char	*type_strings[] = {"TOKEN_REDIR_OUT", "TOKEN_REDIR_IN",
			"TOKEN_WORD", "TOKEN_SPACE", "TOKEN_PIPE", "TOKEN_DQUOTE",
			"TOKEN_SQUOTE", "TOKEN_EOF"};

	return (type <= TOKEN_EOF ? type_strings[type] : "UNKNOWN_TYPE");
}

void	print_token_list(t_list *list)
{
	t_list		*current;
	t_token		*token;
	const char	*content;

	current = list;
	while (current != NULL)
	{
		token = (t_token *)current->content;
		content = token->token ? token->token : "(null)"; // Use value field
		printf("Type: %-15s | Content: %s\n", token_type_to_str(token->type),
			content);
		if (token->type == TOKEN_EOF)
			break ;
		current = current->next;
	}
}

void	print_command(t_command *cmd)
{
	int	i;

	if (!cmd)
		return ;
	printf("Command:\n");
	printf("  Args: ");
	if (cmd->args)
	{
		i = 0;
		while (cmd->args[i] != NULL)
		{
			printf("%s ", cmd->args[i]);
			i++;
		}
	}
	printf("\n");
	printf("  Input File: %s\n", cmd->input_file ? cmd->input_file : "(null)");
	printf("  Output File: %s\n",
		cmd->output_file ? cmd->output_file : "(null)");
}

void	print_ast(t_ast *ast)
{
	if (!ast)
		return ;
	printf("Abstract Syntax Tree:\n");
	print_command(ast->pipeline); // Just print first command
	printf("Background: %s\n", ast->background ? "yes" : "no");
}
