/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:45:54 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/24 17:56:06 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, ft_strlen(s1) + 1);
	ft_strlcat(dest, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (dest);
}
// #include <stdio.h>
// int main()
// {
// 	char *str = "Ciao ";
// 	char *str1 = "Mondo";
// 	printf("%s", ft_strjoin(str, str1));
// }