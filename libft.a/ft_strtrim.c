/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:09:47 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/21 12:14:57 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char const *str, char const *to_find)
{
	int			i;
	int			c;
	static int	count;

	i = 0;
	c = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i + c] == to_find[c] && str[i + c] != '\0')
			c++;
		if (to_find[c] == '\0')
			count++;
		c = 0;
		i++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		c;
	int		j;

	i = 0;
	j = 0;
	dest = (char *)malloc(ft_strlen(s1) - (ft_set(s1, set) * ft_strlen(set)));
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		c = 0;
		while (s1[i + c] == set[c] && s1[i + c] != '\0')
			c++;
		if (set[c] == '\0')
			i += ft_strlen(set);
		dest[j] = s1[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
// #include <stdio.h>
// int main()
// {
// 	char *str = "Ciao Mondoao";
// 	char *set = "a";
// 	printf("%s", ft_strtrim(str, set));
// }