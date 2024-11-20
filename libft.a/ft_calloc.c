/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:19:00 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/20 11:18:19 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	*arr;
	size_t	i;

	i = 0;
	arr = (size_t *)malloc(num * size);
	if (arr == NULL)
		return (NULL);
	while (i < num)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     int *arr;
//     size_t num_elements = 5;
//     // Alloca memoria per un array di 5 interi
//     arr = (int *)ft_calloc(num_elements, sizeof(int));
//     if (arr == NULL) {
//         printf("Errore di allocazione memoria\n");
//         return 1;
//     }
//     // Stampa i valori dell'array (dovrebbero essere tutti zero)
//     for (size_t i = 0; i < num_elements; i++) {
//         printf("arr[%zu] = %d\n", i, arr[i]);
//     }
//     // Libera la memoria
//     free(arr);
//     return 0;
// }