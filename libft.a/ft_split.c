/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:04:59 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/22 15:04:53 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_wrld(char const *s, char c)
{
	int		wrld;
	size_t	i;

	wrld = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wrld++;
		i++;
	}
	return (wrld);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;
	size_t	len_s;

	len_s = ft_strlen(s);
	ptr = (char *) malloc(sizeof(char) * (len_s + 1));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, n + 1);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		wrld;
	int		i;
	int		end;
	int		start;

	wrld = ft_count_wrld(s, c);
	tab = (char **) malloc(sizeof(char *) * (wrld + 1));
	if (tab == NULL || s == NULL)
		return (NULL);
	i = 0;
	end = 0;
	while (i < wrld)
	{
		while (s[end] != c)
			end++;
		tab[i] = ft_strndup((char *)&s[start], end - start);
		if (s[end] == c)
			start = end + 1;
		end++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
// int main()
// {
// 	char str1[] = "Ciao come va?";
//     char **split1 = ft_split(str1, ' ');
// 	int i = 0;
//     while (split1[i] != NULL)
// 	{
//         printf("%s\n", split1[i]);
//         i++;
//     }
// }
