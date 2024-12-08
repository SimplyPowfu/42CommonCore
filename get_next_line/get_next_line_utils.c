/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:48:38 by ecarbona          #+#    #+#             */
/*   Updated: 2024/12/08 21:51:06 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str)
	{
		if (str[i] == (char)c)
		{
			i++;
			return ((char *)&str[i]);
		}
		i++;
	}
	if (c == 0)
		return ((char *)&str[i]);
	return (NULL);
}
static char	*ft_strcpy(char *dest, const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*temp;

	temp = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	ft_strcpy(temp, s);
	return (temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	char		*r;
	size_t		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
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
