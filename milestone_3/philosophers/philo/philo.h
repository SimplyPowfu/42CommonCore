/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:21:01 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/02 17:45:10 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		philo;//thread filosofo
	int				id;//indice del filosofo
	pthread_mutex_t	*fork;//forchetta alla sinistra
	pthread_mutex_t	*r_fork;//forchetta alla destra
	int				is_dead;//bool 0 vivo, 1 morto
	int				is_full;//bool 0 fame, 1 sazio
	int				n_eating;//mangiate totali
	long			last_eat;//ultima mangiata effettuata, tempo - valore = quanto tempo fa ha mangiato 
}	t_philo;

typedef struct s_table
{
	t_philo			**philos;//thread filosofo
	int				n_philo;//numero di filosofi
	int				die_time;//tempo impiegato per morire
	int				eat_time;//tempo impiegato per mangiare
	int				sleep_time;//tempo impiegato per dormire
	int				n_eat;//numero di mangiate per concludere il programma, if 0 is off
	long			start;//inizio simulazione
}	t_table;

int		take_args(t_table *table, char **av);
long	ft_atoi(const char *str);
void	init(t_table *table);
long	take_time();


#endif