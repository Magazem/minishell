/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-24 12:49:35 by ysuliman          #+#    #+#             */
/*   Updated: 2025-02-24 12:49:35 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token_type	peek(t_list *tokens)
{
	if (!tokens || !tokens->content)
	{
		return (TOKEN_EOF);
	}
	return (((t_token *)tokens->content)->type);
}

t_token	*consume_token(t_list **tokens)
{
	t_token	*token;
	t_list	*next_node;

	if (!tokens || !*tokens || !(*tokens)->content)
	{
		return (NULL);
	}
	token = (t_token *)((*tokens)->content);
	next_node = (*tokens)->next;
	free(*tokens);
	*tokens = next_node;
	return (token);
}

static char	**allocate_new_args(char **args, int *count)
{
	char	**new_args;
	int		i;

	*count = 0;
	if (args)
	{
		while (args[*count] != NULL)
		{
			(*count)++;
		}
	}
	new_args = (char **)malloc(sizeof(char *) * ((*count) + 2));
	if (!new_args)
	{
		perror("malloc");
		return (NULL);
	}
	for (i = 0; i < *count; i++)
	{
		new_args[i] = args[i];
	}
	return (new_args);
}

static char	**add_new_argument(char **new_args, int count, char *new_arg)
{
	new_args[count] = ft_strdup(new_arg);
	if (!new_args[count])
	{
		perror("ft_strdup");
		return (NULL);
	}
	new_args[count + 1] = NULL;
	return (new_args);
}

char	**add_argument(char **args, char *arg)
{
	char	**new_args;
	int		count;

	new_args = allocate_new_args(args, &count);
	if (!new_args)
		return (NULL);
	new_args = add_new_argument(new_args, count, arg);
	if (args)
		free(args);
	return (new_args);
}
