/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:01:13 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/10 11:54:02 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
		return (printf("Invalid Arguments\n"), 1);
	if (!take_args(&table, argv))
		return (printf("Error\n"), 1);
	init(&table);
	// printf("numero di filosofi: %d\ntempo per morire: %d\ntempo per mangiare %d\ntempo per dormire: %d\nnumero di mangiate: %d\ninizio simulazione: %ld\n", table.n_philo, table.die_time, table.eat_time, table.sleep_time, table.n_eat, table.start);
	return (0);
}
