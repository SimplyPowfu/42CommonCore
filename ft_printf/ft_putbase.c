/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:26:36 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/28 00:54:14 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(unsigned long n)
{
	unsigned long	temp;
	int				i;

	temp = n;
	i = 0;
	if (n == 0)
		return (write (1, "0", 1), 1);
	while (temp > 0)
	{
		temp /= 16;
		i++;
	}
	return (ft_conv(i, n, "0123456789abcdef"));
}
