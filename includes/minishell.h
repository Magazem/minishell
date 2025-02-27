/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:40:11 by ysuliman          #+#    #+#             */
/*   Updated: 2025/02/07 18:58:44 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include "structs.h"
# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# define PROMPT "minishell% "

t_list			*lexer(char *input);
void			signal_init(void);
t_token			*get_operator(const char *input, int *i);
int				is_operator(char c);
void			print_token_list(t_list *list);
t_token			*consume_token(t_list **tokens);
char			**add_argument(char **args, char *arg);
t_token_type	peek(t_list *tokens);
t_command		*parse_command(t_list **tokens);
void			print_ast(t_ast *ast);
void			print_command(t_command *cmd);
t_ast			*parse_body(t_list **tokens);
#endif