/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:19:34 by glancell          #+#    #+#             */
/*   Updated: 2025/03/28 21:29:42 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*str;

	if (!dest && !src)
		return (dest);
	i = 0;
	dst = dest;
	str = src;
	if (dest <= src)
	{
		while (n--)
		{
			dst[i] = str[i];
			i++;
		}
	}
	else
	{
		while (i + 1 <= n--)
			dst[n] = str[n];
	}
	return (dst);
}
