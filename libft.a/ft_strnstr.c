/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:20:25 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/22 15:23:25 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (*little == '\0')
		return (big);
	while (big[i] != '\0' && i < len)
	{
		c = 0;
		while (big[i + c] == little[c] && big[i + c] != '\0')
			c++;
		if (little[c] == '\0')
			return (&big[i]);
		i++;
	}
	return (0);
}
// #include <stdio.h>
// int     main()
// {
// 	char    str[] = "eliminaCOPIAelimina";
// 	char    find[] = "PIA";
// 	printf("%s", ft_strnstr(str, find, 13));
// }