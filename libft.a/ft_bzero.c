/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:09:53 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/14 17:16:34 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void ft_bzero(void *s, size_t n)
{
    char *p = s;
    while(n--)
    {
        *p++ = 0;
    }
}
/* 
#include <stdio.h>
#include <strings.h>

int main() {
    char buffer[10];
    ft_bzero(buffer, sizeof(buffer));    
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer[i]);
    }
    return 0;
} */