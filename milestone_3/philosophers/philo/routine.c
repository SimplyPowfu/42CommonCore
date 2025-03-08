/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:36:25 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/08 19:30:00 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	print_mess("is thinking", philo->table->start ,philo->id);
}

void	sleeping(t_philo *philo)
{
	print_mess("is sleeping", philo->table->start ,philo->id);
	usleep(philo->table->sleep_time);
	thinking(philo);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork);
	print_mess("has taken a fork", philo->table->start, philo->id);
	pthread_mutex_lock(philo->r_fork);
	print_mess("has taken a fork", philo->table->start, philo->id);
	philo->last_eat = take_time();
	print_mess("is eating", philo->table->start ,philo->id);
	philo->n_eating++;
	usleep(philo->table->eat_time);//simulazione pasto
	philo->is_full = 1;
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->r_fork);
	sleeping(philo);
}

void	routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if(philo->id % 2 == 0)
		sleeping(philo);
	while (philo->is_dead == 0)
		eating(philo);
	// while(!f_eat(table, philos) || !is_dead(philos))
	// {

	// }
}
