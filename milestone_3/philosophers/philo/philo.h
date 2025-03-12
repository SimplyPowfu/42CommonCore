/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:21:01 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/12 17:57:00 by ecarbona         ###   ########.fr       */
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
}	t_table;

typedef struct s_philo
{
	pthread_t		philo;//thread filosofo
	long				id;//indice del filosofo
	pthread_mutex_t	*fork;//forchetta alla sinistra
	pthread_mutex_t	*r_fork;//forchetta alla destra
	long				is_dead;//bool 0 vivo, 1 morto
	long				is_full;//bool 0 fame, 1 sazio
	long				n_eating;//mangiate totali
	long			last_eat;//ultima mangiata effettuata, tempo - valore = quanto tempo fa ha mangiato
	t_table			*table;
}	t_philo;

int		take_args(t_table *table, char **av);
long	ft_atoi(const char *str);
void	init(t_table *table);
long	take_time();
void	print_mess(char *str, long start, int id);
void	*routine(void *arg);
int		f_eat(t_philo *philos);
int		is_dead(t_philo *philos);
void	free_philo(t_philo **philos);

#endif