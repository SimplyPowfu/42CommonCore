/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:20:25 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/20 11:12:28 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, int len)
{
	int	i;
	int	c;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0' && i < len)
	{
		c = 0;
		while (str[i + c] == to_find[c] && str[i + c] != '\0')
			c++;
		if (to_find[c] == '\0')
			return (&str[i]);
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