/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:36:25 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/06 18:37:55 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_table *table ,t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_mess("has taken a fork", table->start, philo->id);
	pthread_mutex_lock(&philo->r_fork);
	print_mess("has taken a fork", table->start, philo->id);
	print_mess("is eating", table->start ,philo->id);
	usleep(table->eat_time);//simulazione pasto
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->r_fork);
}
void	sleeping(t_table *table ,t_philo *philo)
{
	print_mess("is sleeping", table->start ,philo->id);
	usleep(table->sleep_time);
}
void	thinking(t_table *table, t_philo *philo)
{
	print_mess("is thinking", table->start ,philo->id);
}

void	routine(t_table *table, t_philo *philo)
{
	
}
