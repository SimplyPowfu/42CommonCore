/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:21:01 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/27 17:57:45 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_table
{
	long				n_philo;
	long				die_time;
	long				eat_time;
	long				sleep_time;
	long				n_eat;
	long				start;
	long				is_finish;
	pthread_mutex_t		*printing;
	pthread_mutex_t		*simulation;
}	t_table;

typedef struct s_philo
{
	pthread_t		philo;
	long			id;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*r_fork;
	long			n_eating;
	long			last_eat;
	t_table			*table;
}	t_philo;

int		take_args(t_table *table, char **av);
long	ft_atoi(const char *str);
void	init(t_table *table);
long	take_time(void);
void	print_mess(t_philo *philo, char *str, long start, int id);
void	*routine(void *arg);
int		f_eat(t_philo *philos);
int		is_dead(t_philo *philos);
void	free_philo(t_philo **philos);

#endif