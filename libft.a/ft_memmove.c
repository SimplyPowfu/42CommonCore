/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:19:34 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/14 16:33:43 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void *ft_memmove(void *dest, void *src, unsigned int len)
{
	unsigned char *dest1 = dest;
	unsigned char *src1 = src;
	unsigned int i = 0;

	while(i < len)
	{
		dest1[i] = src1[i];
		i++;
	}
}
/*
int main()
{
	char str[] = "Hello, World!";
	ft_memmove(str + 7, str, 5);
	printf("%s\n", str);
}*/