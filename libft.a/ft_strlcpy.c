/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:42:51 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/17 17:41:41 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
    int	i;

	i = 0;
	while (dest[i] != '\0' && i < size - 1)
	{
		if (dest[i] < src[i] || dest[i] > src[i])
		{
			return (dest[i] - src[i]);
		}
		i++;
	}
	return (dest[i] - src[i]);
}
/* 
#include <stdio.h>
int	main()
{
	printf("%ld", ft_strlcpy("Hello", "Hello1", 5));
	printf("\n%ld", ft_strlcpy("Hello", "He", 6));
	printf("\n%ld", ft_strlcpy("He", "Hello", 2));
	printf("\n%ld\n", ft_strlcpy("Hello", "Hello", 3));
} */