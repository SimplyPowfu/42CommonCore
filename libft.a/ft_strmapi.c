/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:03:18 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/20 18:48:06 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str || !s)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
// #include <stdio.h>
// char ft_mytoupper(unsigned int i, char c)
// {
//     (void)i;
//     if (c >= 'a' && c <= 'z')
//     {
//         return c - 'a' + 'A';
//     }
//     return c;
// }
// int main()
// {
// 	char str[] = "ciao";
// 	printf("%s", ft_strmapi(str, ft_mytoupper));
// }