/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:46:37 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/14 17:16:45 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memset(void *ptr, int value, size_t num)
{
    char *p = ptr;
    while(num--)
    {
        *p++ = value;
    }
    return ptr;
}
/* 
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    ft_memset(buffer, '0', sizeof(buffer));

    printf("Buffer dopo memset: %s\n", buffer);  // Output: Buffer dopo memset: ---------
    return 0;
}  */