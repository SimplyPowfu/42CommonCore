/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:25:24 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/31 19:16:02 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int echo(int argc, char **argv)
{
	int	i;

	i = 0;
	if(argc <= 1)
		return(write(1, "\n", 1), 0);
	if (argv[1][0] == '-' && argv[1][1] == 'n')
		i++;
	while(++i < argc)
	{
		if (argv[i][i] == '$' && argv[i][i + 1] == '?')
			printf("%d", g_signal_error);
		else
		{
			printf("%s", argv[i]);
			if (i != argc - 1)
				printf(" ");
		}
	}
	if (argv[1][0] != '-' && argv[1][1] != 'n')
		printf("\n");
	return (1);
}

int main(int argc, char **argv)
{
	echo(argc, argv);
	return (0);
}
