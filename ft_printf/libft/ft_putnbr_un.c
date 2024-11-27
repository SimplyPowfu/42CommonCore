/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:21:45 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/27 14:27:36 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnbr_un(unsigned int n)
{
	unsigned int		temp;
	char				*array;
	char				*base;
	int					i;

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
