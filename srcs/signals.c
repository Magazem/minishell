/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:33:30 by ysuliman          #+#    #+#             */
/*   Updated: 2025/02/01 18:27:09 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ctrl_back_slash(int signum)
{
	struct termios	term;

	(void)signum;
	rl_on_new_line();
	rl_redisplay();
	tcgetattr(STDIN_FILENO, &term);
	term.c_cc[VQUIT] = _POSIX_VDISABLE;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	ctrl_c(int signum)
{
	(void)signum;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", -1);
	rl_redisplay();
}

void	signal_init(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	ft_memset(&sa_int, 0, sizeof(sa_int));
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_handler = &ctrl_c;
	sa_int.sa_flags = 0;
	sigaction(SIGINT, &sa_int, NULL);
	ft_memset(&sa_quit, 0, sizeof(sa_quit));
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_handler = &ctrl_back_slash;
	sa_quit.sa_flags = 0;
	sigaction(SIGQUIT, &sa_quit, NULL);
}
