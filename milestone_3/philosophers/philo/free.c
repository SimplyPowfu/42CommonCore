/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:53:58 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/10 17:25:48 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo **philos)
{
	int	i;

	int philo = philos[0]->table->n_philo;
	i = -1;
	while (++i < philo)
	{
		pthread_mutex_destroy(philos[i]->fork);
		free(philos[i]->fork);
		free(philos[i]);
	}
	free(philos);
}