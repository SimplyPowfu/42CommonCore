/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:19:16 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/21 12:13:56 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *dest, const void *src, size_t len)
{
	const char	*dest1;
	const char	*src1;
	size_t		i;

	dest1 = dest;
	src1 = src;
	i = 0;
	while (i < len)
	{
		if (dest1[i] != src1[i])
			return (dest1[i] - src1[i]);
		i++;
	}
	return (0);
}
// int main() {
// 	char str1[] = "Hello";
// 	char str2[] = "Hello, World!";

// 	int result = ft_memcmp(str1, str2, 5);  // Confronta i primi 5 byte
// 	if (result == 0) {
// 		printf("I primi 5 caratteri sono uguali.\n");
// 	} else {
// 		printf("I primi 5 caratteri sono diversi.\n");
// 	}
// 	printf("%d\n", result);
// 	return 0;
// }