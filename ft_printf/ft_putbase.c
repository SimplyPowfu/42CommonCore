/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:26:36 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/26 17:29:35 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

static void	ft_print(int nbr, int b, char *base)
{
	if (nbr == b)
		write (1, &base[b], 1);
	if (nbr < b)
		write (1, &base[nbr % b], 1);
}

	void	ft_putbase(unsigned int nbr, char *base)
{
	int	b;

	b = ft_base(base);
	if (b >= 2 && ft_check(base) == 1)
	{
		if (nbr >= b)
		{
			ft_putbase(nbr / b, base);
			ft_putbase(nbr % b, base);
		}
		ft_print(nbr, b, base);
	}
}
