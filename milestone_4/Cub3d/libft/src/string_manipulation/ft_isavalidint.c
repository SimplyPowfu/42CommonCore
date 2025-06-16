/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isavalidint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:54:57 by glancell          #+#    #+#             */
/*   Updated: 2025/03/28 21:29:42 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static int	is_non_empty(char *str, int i)
{
	return (str[i] != '\0');
}

static int	check_digits(char c)
{
	return (ft_isdigit(c));
}

static int	check_overflow(long num, int sign)
{
	if (sign == 1)
		return (num > INT_MAX);
	else
		return (num * sign < INT_MIN);
}

int	is_valid_int(char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	sign = check_sign(str, &i);
	if (!is_non_empty(str, i))
		return (0);
	while (str[i])
	{
		if (!check_digits(str[i]))
			return (0);
		num = num * 10 + (str[i] - '0');
		if (check_overflow(num, sign))
			return (0);
		i++;
	}
	return (1);
}
