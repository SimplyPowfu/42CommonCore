/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:34:24 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/26 03:51:56 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_time(t_table *table)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	table->start = (time.tv_sec * 1e3) + (time.tv_usec / 1e3);
}

void	init(t_table *table)
{
	t_philo	**philos;
	int		i;

	i = -1;
	philos = malloc(sizeof(t_philo) * table->n_philo);
	table->philos = philos;
	while (++i < table->n_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		philos[i]->id = i;
		philos[i]->is_dead = 0;
		philos[i]->is_full = 0;
		philos[i]->n_eating = 0;
		philos[i]->last_eat = 0;
		if (i == 0)
			philos[i]->fork = malloc(sizeof(pthread_mutex_t));
		else
		{
			philos[i]->fork = malloc(sizeof(pthread_mutex_t));
			philos[i]->r_fork = philos[i - 1]->fork;
		}
		pthread_mutex_init(philos[i]->fork, 0);
	}
	philos[0]->r_fork = philos[i]->fork;
	take_time(table);
}

int	take_args(t_table *table, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i] != NULL)
	{
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != ' ' &&
				av[i][j] != '+')
				return (printf("Only numbers, "), 0);
		}
		if (ft_atoi(av[i]) < -2147483648 || ft_atoi(av[i]) > 2147483647)
			return (printf("Only INT numbers, "), 0);
	}
	table->n_philo = ft_atoi(av[1]);
	table->die_time = ft_atoi(av[2]);
	table->eat_time = ft_atoi(av[3]);
	table->sleep_time = ft_atoi(av[4]);
	if (av[5])
		table->n_eat = ft_atoi(av[5]);
	else
		table->n_eat = 0;
	return (1);
}
