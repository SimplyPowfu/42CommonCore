/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:36:25 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/02 17:55:43 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mess(char *str, long start, int id)
{
	long	time;

	time = take_time() - start;
	printf("%ld, %s, %d", time, str, id);
}

void	eating(t_philo *philo)
{
	
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
