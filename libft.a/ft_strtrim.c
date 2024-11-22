/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:09:47 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/22 16:45:12 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, char const *set)
{
	char		*dest;
	size_t		start;
	size_t		end;

	start = 0;
	end = strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		++start;
	while (s1[end] && ft_strchr(set, s1[end]))
		--end;
	dest = ft_substr(s1, start, end - start + 1);
	return (dest);
}
// #include <stdio.h>
// int main()
// {
// 	const char *str = "Ciao Mondoi";
// 	const char *set = "ciao";
// 	printf("%s", ft_strtrim(str, set));
// }