/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:55:58 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/17 19:05:28 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memchr(const void *ptr, int c, size_t n)
{
    int i;
    char *str;

    str = (char *)ptr;
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == (char)c)
        {
            return ((void *)&str[i]);
        }
        i++;
    }
    return (NULL);
}
/*
#include <stdio.h>
int main() {
    const char buffer[] = "Ciao, mondo!";
    unsigned char byte_to_find = 'o';
    void *result = ft_memchr(buffer, byte_to_find, sizeof(buffer));
    printf("%p\n", result);
} */
