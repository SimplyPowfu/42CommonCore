/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:42:51 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/19 10:42:17 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j] != '\0')
		j++;
	i = 0;
	while (i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
// #include <stdio.h>
// #include <bsd/string.h>
// int main()
// {
//     char src[] = "Hello, world!";
//     char dst[10]; // Buffer di dstinazione di dimensione 10
//     size_t len = ft_strlcpy(dst, src, sizeof(dst));
//     printf("Dst: %s\n", dst);
//     printf("Length: %zu\n", len);
//     return 0;
// }