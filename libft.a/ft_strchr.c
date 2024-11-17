/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:12:57 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/17 18:48:48 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char *ft_strchr(const char *str, int c)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == (char)c)
        {
            return ((char *)&str[i]);
        }
        i++;
    }
    return (NULL);
}
/* 
#include <stdio.h>
int main()
{
    const char *str = "Ciao, mondo!";
    char to_find = 'o';
    char *result = ft_strchr(str, to_find);
    printf("%s", result);
} */