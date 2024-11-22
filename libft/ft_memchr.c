/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:55:58 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/22 14:58:05 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;

	str = (unsigned char *)s;
	i = 0;
	while ((str[i] != '\0') && (i < n - 1))
	{
		if (str[i] == (unsigned char)c)
		{
			return ((void *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// int main() {
//     const char buffer[] = "Ciao, mondo!";
//     unsigned char byte_to_find = 'o';
//     void *result = ft_memchr(buffer, byte_to_find, sizeof(buffer));
//     printf("%p\n", result);
// }
