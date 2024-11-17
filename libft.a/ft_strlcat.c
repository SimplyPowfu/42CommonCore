/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:43:46 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/17 18:37:57 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
    int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0' && j < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (i);
}
/* 
#include <stdio.h>
#include <string.h>
int main() {
    char dest[20] = "Ciao, ";
    const char *src = "come va?";
    
    printf("%ld\n", ft_strlcat(dest, src, sizeof(dest)));
    
    printf("%s\n", dest);  // Output: "Ciao, come va?"
    
    return 0;
} */