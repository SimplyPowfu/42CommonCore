/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:30:24 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/21 10:21:26 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// #include <stdio.h>
// #include <string.h>
// void to_uppercase(unsigned int i, char *c)
// {
// 	(void)i;
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - 32;
// }
// int main(void)
// {
// 	char str[] = "hello, world!";
// 	printf("Original string: %s\n", str);
// 	ft_striteri(str, to_uppercase);
// 	printf("Modified string: %s\n", str);
// 	return 0;
// }
