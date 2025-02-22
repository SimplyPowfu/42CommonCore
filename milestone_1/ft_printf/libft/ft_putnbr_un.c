/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:21:45 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/28 00:31:50 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include "../ft_printf.h"

int	ft_putnbr_un(unsigned int n)
{
	unsigned int	temp;
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (write(1, "0", 1), 1);
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		i++;
	}
	return (ft_conv(i, n, "0123456789"));
}
