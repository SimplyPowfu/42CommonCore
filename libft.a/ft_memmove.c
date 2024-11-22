/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:19:34 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/22 15:02:36 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*str;

	i = 0;
	dst = dest;
	str = src;
	if (dest <= src)
	{
		while (n--)
		{
			dst[i] = str[i];
			i++;
		}
	}
	else
	{
		while (i + 1 <= n)
		{
			n--;
			dst[n] = str[n];
		}
	}
	return (dst);
}
// #include <stdio.h>
// int main() {
//     char buffer[20] = "Ciao mondo!!!!!!!!";
//     printf("Buffer: %s\n", (char *)ft_memmove(NULL, NULL, 0));
//     return 0;
// }