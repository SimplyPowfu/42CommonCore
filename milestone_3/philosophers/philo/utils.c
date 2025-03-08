/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:22:47 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/08 16:07:13 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	f_eat(t_table *table, t_philo **philos)
{
	int	finish;
	int i;

	finish = 0;
	i = -1;
	while(philos[++i])
	{
		if(philos[i]->n_eating >= table->n_eat)
			finish++;
	}
	if (finish == table->n_philo)
		return (1);
	return (0);
}

int	is_dead(t_philo **philos)
{
	int	i;

	i = -1;
	while (philos[++i])
		if (philos[i]->is_dead != 0)
			return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	atoi;
	int		min;

	i = 0;
	atoi = 0;
	min = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min = -min;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi = ((atoi * 10) + (str[i] - 48));
		i++;
	}
	return (atoi * min);
}

void	print_mess(char *str, long start, int id)
{
	long	time;

	time = take_time() - start;
	printf("%ld, %d, %s", time, id, str);
}
