/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:20:14 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/27 14:26:24 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_putnbr_fd(int n)
{
	int		temp;
	char	*array;
	char	*base;
	int		i;

	base = "0123456789";
	temp = n;
	i = 0;
	while (temp > 0)
	{
		temp /= 10;
		i++;
	}
	array = malloc(sizeof(char) * (i + 1));
	array[i] = '\0';
	while (n > 0)
	{
		array[--i] = base[n % 10];
		n = n / 10;
	}
	while (array[i])
		write (1, &array[i++], 1);
	free (array);
	return (i);
}
