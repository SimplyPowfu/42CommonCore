/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:20:25 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/24 17:14:00 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (len == 0)
		return (NULL);
	if (*little == 0)
		return ((char *)big);
	while (big[i] != '\0' && i <= len)
	{
		c = 0;
		while (big[i + c] == little[c] && big[i + c] != '\0' && i + c < len)
			c++;
		if (little[c] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// int     main()
// {
// 	char    str[] = "eliminaCOPIAelimina";
// 	//char    find[] = "PIA";
// 	printf("%s", ft_strnstr(str, 0, 10));
// }