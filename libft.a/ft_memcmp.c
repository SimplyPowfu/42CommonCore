/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:19:16 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/18 16:49:04 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_memcmp(void *dest, void *src, unsigned int len)
{
	unsigned char *dest1 = dest;
	unsigned char *src1 = src;
	unsigned int i = 0;

	while(i < len)
	{
		if (dest1[i] != src1[i])
            return (dest1[i] - src1[i]);
		i++;
	}
    return (0);
}
/*
int main() {
    char str1[] = "Hello";
    char str2[] = "Hello, World!";
    
    int result = ft_memcmp(str1, str2, 5);  // Confronta i primi 5 byte

    if (result == 0) {
        printf("I primi 5 caratteri sono uguali.\n");
    } else {
        printf("I primi 5 caratteri sono diversi.\n");
    }
    printf("%d\n", result);
    return 0;
}*/