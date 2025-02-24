/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:21:01 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/24 19:54:05 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_fork
{
	pthread_mutex_t	*forc;//forchetta (blocca la variabile e la sblocca quando un threads ha finito di usarla)
	int				taked;
}	t_fork;

typedef struct s_philo
{
	pthread_t		*philo;//thread filosofo
	t_fork			*r_fork;//forchetta alla destra
	t_fork			*l_fork;//forchetta alla sinistra
	int				is_dead;//bool 0 morto, 1 vivo
	int				is_full;//bool 0 fame, 1 sazio
	int				n_eating;//mangiate totali
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;//thread filosofo
	int				n_philo;//numero di filosofi
	int				die_time;//tempo impiegato per morire
	int				eat_time;//tempo impiegato per mangiare
	int				sleep_time;//tempo impiegato per dormire
	int				n_eat;//numero di mangiate per concludere il programma, if 0 is off
}	t_table;

int		take_args(t_table *table, char **av);
long	ft_atoi(const char *str);

#endif