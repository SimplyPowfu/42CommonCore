/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:23:29 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/17 16:43:19 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    int i;
	const char *str;
	char *cpy;

	i = 0;
	str = src;
	cpy = dest;
	while(str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	return (cpy);
}
/*
#include <stdio.h>

int main(void)
{
    char source[] = "This is the source string";
    char target[] = "Cringe";
  printf( "%s\n", target );
  ft_memcpy( target, source, sizeof(source));
  printf( "%s\n", target );
} */