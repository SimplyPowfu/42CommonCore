/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:20:25 by glancell          #+#    #+#             */
/*   Updated: 2025/03/29 18:54:01 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
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
