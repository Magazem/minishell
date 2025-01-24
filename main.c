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

int	main(void)
{
	char	*line;
	int		x;

	x = 0;
	while (x < 5)
	{
		line = readline(PROMPT);
		add_history(line);
		free(line);
		x++;
	}
	clear_history();
	return (0);
}
