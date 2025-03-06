/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:22:47 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/06 18:02:24 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
