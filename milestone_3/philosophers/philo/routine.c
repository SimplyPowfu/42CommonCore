/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:36:25 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/10 12:55:46 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking(t_philo *philo)
{
	if (philo->is_dead == 1)
		return (-1);
	print_mess("is thinking\n", philo->table->start ,philo->id);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (philo->is_dead == 1)
		return (-1);
	print_mess("is sleeping\n", philo->table->start ,philo->id);
	usleep(philo->table->sleep_time);
	if (thinking(philo) == -1)
		return (-1);
	return (0);
}

int	eating(t_philo *philo)
{
	if (philo->is_dead == 1)
		return (-1);
	pthread_mutex_lock(philo->fork);
	print_mess("has taken a fork\n", philo->table->start, philo->id);
	pthread_mutex_lock(philo->r_fork);
	print_mess("has taken a fork\n", philo->table->start, philo->id);
	philo->last_eat = take_time();
	print_mess("is eating\n", philo->table->start ,philo->id);
	philo->n_eating++;
	usleep(philo->table->eat_time);//simulazione pasto
	philo->is_full = 1;
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->r_fork);
	if (sleeping(philo) == -1)
		return (-1);
	return (0);
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if(philo->id % 2 == 0)
		sleeping(philo);
	while (philo->is_dead == 0)
	{
		if (eating(philo) == -1)
			break ;
	}
	return (philo);
}
