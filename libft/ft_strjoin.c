/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:45:54 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/22 15:17:14 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncat(char *dst, const char *dest,
						const char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		dst[i] = dest[i];
		i++;
	}
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dest)
		return (NULL);
	dest = ft_strncat(dest, s1, s2, sizeof(dest));
	return (dest);
}
// #include <stdio.h>
// int main()
// {
// 	char *str = "Ciao ";
// 	char *str1 = "Mondo";
// 	printf("%s", ft_strjoin(str, str1));
// }