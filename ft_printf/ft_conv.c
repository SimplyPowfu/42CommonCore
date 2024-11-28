/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:07:31 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/27 23:54:59 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv(int i, unsigned long n, char *base)
{
	char	*array;
	int		b;

	b = ft_strlen(base);
	array = malloc(sizeof(char) * (i + 1));
	if (!array)
		return (0);
	array[i] = '\0';
	while (n > 0)
	{
		array[--i] = base[n % b];
		n = n / b;
	}
	while (array[i])
		write (1, &array[i++], 1);
	free (array);
	return (i);
}
