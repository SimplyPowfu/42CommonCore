/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:09:53 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/19 09:59:46 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n--)
		*p++ = 0;
}
// #include <stdio.h>
// int main() {
//     char buffer[10];
//     ft_bzero(buffer, sizeof(buffer));    
//     for (int i = 0; i < 10; i++) {
//         printf("%d ", buffer[i]);
//     }
//     return 0;
// }