/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:01:13 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/08 19:33:11 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;
	t_philo *philos;

	if (argc < 5 || argc > 6)
		return (printf("Invalid Arguments\n"), 1);
	if (!take_args(&table, argv))
		return (printf("Error\n"), 1);
	init(&table, &philos);
	// init_thread(&table, &philos);
	return (0);
}
