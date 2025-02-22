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
	char		*str;
	char		*r;
	size_t		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	r = str;
	while (s1 && *s1 != '\0')
	{
		*str = *s1;
		s1++;
		str++;
	}
	while (s2 && *s2 != '\0')
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
	return (r);
}
