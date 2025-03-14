/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:21:01 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/14 15:45:07 by ecarbona         ###   ########.fr       */
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
	long				n_philo;//numero di filosofi
	long				die_time;//tempo impiegato per morire
	long				eat_time;//tempo impiegato per mangiare
	long				sleep_time;//tempo impiegato per dormire
	long				n_eat;//numero di mangiate per concludere il programma, if 0 is off
	long				start;//inizio simulazione
	long				is_finish;
	pthread_mutex_t		*printing;
	pthread_mutex_t		*simulation;
}	t_table;

typedef struct s_philo
{
	pthread_t		philo;//thread filosofo
	long			id;//indice del filosofo
	pthread_mutex_t	*fork;//forchetta alla sinistra
	pthread_mutex_t	*r_fork;//forchetta alla destra
	long			n_eating;//mangiate totali
	long			last_eat;//ultima mangiata effettuata, tempo - valore = quanto tempo fa ha mangiato
	t_table			*table;
}	t_philo;

int		take_args(t_table *table, char **av);
long	ft_atoi(const char *str);
void	init(t_table *table);
long	take_time();
void	print_mess(t_philo *philo, char *str, long start, int id);
void	*routine(void *arg);
int		f_eat(t_philo *philos);
int		is_dead(t_philo *philos);
void	free_philo(t_philo **philos);

#endif