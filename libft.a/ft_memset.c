/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:46:37 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/22 15:02:59 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = s;
	while (n--)
	{
		*p++ = c;
	}
	return (s);
}
// #include <stdio.h>
// int main() {
// 	char buffer[10];
// 	ft_memset(buffer, '0', sizeof(buffer));

// 	printf("Buffer dopo memset: %s\n", buffer);
// 	return 0;
// }