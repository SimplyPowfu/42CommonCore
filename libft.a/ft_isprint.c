/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:37:59 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/18 16:49:01 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int ft_isprint(char c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
/*
int main()
{
	printf("%d\n", isprint(' '));
	printf("%d\n", ft_isprint('\n'));
}*/