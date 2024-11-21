/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:05:39 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/21 12:47:21 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	dest = (char *)malloc(len);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, &s[start], len);
	return (dest);
}
// #include <stdio.h>
// int main()
// {
//     char sorgente[] = "Ciao, Mondo!";
//     printf("%s\n", ft_substr(sorgente, 6, 5));
//     return 0;
// }