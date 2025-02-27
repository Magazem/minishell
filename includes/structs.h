/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:27:03 by ysuliman          #+#    #+#             */
/*   Updated: 2025/02/07 18:54:43 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "minishell.h"

//      ############## LEXER STRUCTS ############## //

typedef enum e_token_type
{
	TOKEN_REDIR_OUT, // token for >
	TOKEN_REDIR_IN,  // token for <
	TOKEN_WORD,      // token for commands, paths ...etc
	TOKEN_SPACE,     // token for space and tabs
	TOKEN_PIPE,      // token for |
	TOKEN_DQUOTE,    // token for "
	TOKEN_SQUOTE,    // token for '
	TOKEN_EOF,       // token for End Of File
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*token;
}					t_token;

typedef struct s_data
{
	t_list			*lexer;
}					t_data;

//      ############## PAERSER STRUCTS ############## //

typedef struct s_command
{
	char **args;            // Command + arguments
	char *input_file;       // From < or <<
	char *output_file;      // From > or >>
	struct s_command *next; // Next command in the pipeline (if any)
}					t_command;

typedef struct s_ast
{
	t_command *pipeline; // Commands connected via pipes
	int background;      // & flag
}					t_ast;

#endif