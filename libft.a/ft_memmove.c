/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:19:34 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/18 19:35:17 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void *ft_memmove(void *dst, const void *src, size_t n)
{
	int	i;
	char *dest;
	const char *str;

	i = 0;
	dest = dst;
	str = src;
	if(dst <= src)
	{
		while(n--)
		{
			dest[i] = str[i];
			i++;
		}
	}
	else
	{
		while(i + 1 <= n )
		{
			n--;
			dest[n] = str[n];
		}
	}
	return (dest);
}
#include <stdio.h>
#include <string.h>
int main() {
    char buffer[20] = "Ciao mondo!!!!!!!!";
    ft_memmove(buffer + 5, buffer, 0);
    printf("Buffer: %s\n", buffer);
    return 0;
}