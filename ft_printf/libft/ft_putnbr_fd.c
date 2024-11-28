/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:20:14 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/28 00:04:14 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../ft_printf.h"

int	ft_putnbr_fd(int n)
{
	int		temp;
	int		i;

	i = 0;
	if (n == 0)
		return (write(1, "0", 1), 1);
	else if (n < 0)
	{
		write (1, "-", ++i);
		if (n == -2147483648)
		{
			write(1, "2147483648", 10);
			return (i + 10);
		}
		n = -n;
	}
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		i++;
	}
	return (ft_conv(i, n, "0123456789"));
}
