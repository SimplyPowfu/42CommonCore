/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:47:06 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/17 18:54:33 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char *ft_strrchr(const char *str, int c)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    while(i > 0)
    {
        if(str[i] == (char)c)
        {
            return ((char *)&str[i]);
        }
        i--;
    }
    return (NULL);
}
/*  
#include <stdio.h>
int main()
{
    const char *str = "Ciao, mondo!";
    char to_find = 'n';
    char *result = ft_strrchr(str, to_find);
    printf("%s", result);
} */