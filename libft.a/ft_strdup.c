/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:14:51 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/18 16:49:17 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(const char *src)
{
	int	i;

	i = 0;
	while(src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char *ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_strdup(const char *src)
{
	char	*temp;
// copia   tipologia     grandezza + (+1 '\0') * grandezza in byte
	temp = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if(temp == NULL)
		return NULL; //se la locazione fallisce esci
	ft_strcpy(temp, src);
	return (temp);
}
/* 
#include <stdio.h>
int main()
{
	const char src[] = "Origine";
	char *copy = ft_strdup(src);

	printf("Stringa originale: %s\n", src);
	printf("Stringa copiata: %s\n", copy);
    free(copy);
} */