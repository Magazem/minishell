/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-24 10:50:30 by ysuliman          #+#    #+#             */
/*   Updated: 2025-01-24 10:50:30 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(void)
{
	char	*line;

	rl_on_new_line();
	line = readline(PROMPT);
	add_history(line);
}

int	main(int ac, char **av)
{
	if (ac == 1 && !ft_strncmp(av[0], "./minishell", 12))
	{
		while (1)
		{
			minishell();
		}
	}
	else
		printf("minishell must be run as a standalone command ex: ./minishell\n");
	clear_history();
	return (0);
}
