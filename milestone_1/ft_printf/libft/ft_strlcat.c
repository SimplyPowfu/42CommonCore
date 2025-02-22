/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:43:46 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/23 15:29:53 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	i = 0;
	if (size <= len1)
		return (len2 + size);
	while (len1 + i < size - 1 && src[i] != '\0')
	{
		dst[len1 + i] = src[i];
		i++;
	}
	dst[len1 + i] = '\0';
	return (len1 + len2);
}
// #include <stdio.h>
// #include <bsd/string.h>
// int main() {
//     char dst[20] = "Ciao, ";
//     const char *src = "come va?";
// 	char dst1[20] = "Ciao, ";
//     const char *src1 = "come va?";
//     printf("%ld\n", ft_strlcat(dst, src, 15));
//     printf("%s\n", dst);
// 	printf("%ld\n", strlcat(dst1, src1, 15));
//     printf("%s\n", dst1);
// }