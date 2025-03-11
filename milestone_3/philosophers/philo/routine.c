/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:36:25 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/11 13:23:05 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking(t_philo *philo)
{
	if (is_dead(philo) == 1)
		return (1);
	print_mess("is thinking\n", philo->table->start ,philo->id);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (is_dead(philo) == 1)
		return (1);
	print_mess("is sleeping\n", philo->table->start ,philo->id);
	usleep(philo->table->sleep_time * 1000);
	if (thinking(philo) == 1)
		return (1);
	return (0);
}

int	eating(t_philo *philo)
{
	if (is_dead(philo) == 1 || f_eat(philo) == 1)
		return (1);
	pthread_mutex_lock(philo->fork);
	print_mess("has taken a fork\n", philo->table->start, philo->id);
	pthread_mutex_lock(philo->r_fork);
	print_mess("has taken a fork\n", philo->table->start, philo->id);
	philo->last_eat = take_time();
	print_mess("is eating\n", philo->table->start ,philo->id);
	philo->n_eating++;
	usleep(philo->table->eat_time * 1000);
	philo->is_full = 1;
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->r_fork);
	if (sleeping(philo) == 1)
		return (1);
	return (0);
}

int is_one(t_philo *philo)
{
	print_mess("is sleeping\n", philo->table->start ,philo->id);
	usleep((philo->table->die_time + 1) * 1000);
	is_dead(philo);
	return (0);
}

void	*routine(void *arg)
{
	t_philo *philo;
	int	i;

	i = 0;
	philo = (t_philo *)arg;
	if(philo->id % 2 == 0)
		sleeping(philo);
	while (1)
	{
		if (philo->table->n_philo == 1)
		{
			is_one(philo);
			break ; //funzione dove liberi tutto e poi exit(0); gestione unlock forchette;
		}
		else if (eating(philo) == 1)
			break ; //funzione dove liberi tutto e poi exit(0); gestione unlock forchette;
		i++;
	}
	return (philo);
}
