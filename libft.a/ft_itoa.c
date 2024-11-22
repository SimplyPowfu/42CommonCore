/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:25:47 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/22 14:56:15 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_putnbr(char *str, int nb, int *i)
{
	if (nb == -2147483648)
	{
		str[*i] = '-';
		(*i)++;
		str[*i] = '2';
		(*i)++;
		nb = 147483648;
	}
	if (nb < 0)
	{
		str[*i] = '-';
		(*i)++;
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(str, nb / 10, i);
	}
	str[*i] = (nb % 10) + '0';
	(*i)++;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(ft_size(n) + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_putnbr(str, n, &i);
	str[i] = '\0';
	return (str);
}
// #include <stdio.h>
// int main()
// {
// 	int n = -21;
// 	printf("%s", ft_itoa(n));
// }