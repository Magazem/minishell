/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:50:30 by ysuliman          #+#    #+#             */
/*   Updated: 2025/02/07 18:59:26 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell(t_data *data)
{
	char	*line;

	signal_init();
	rl_on_new_line();
	line = readline(PROMPT);
	data->lexer = lexer(line);
	if (line == NULL)
	{
		printf("exit\n");
		free(line);
		exit(0);
	}
	add_history(line);
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac == 1)
	{
		while (1)
		{
			minishell(&data);
		}
	}
	else
		printf("minishell must be run as a standalone command ex: ./minishell\n");
	clear_history();
	return (0);
}
