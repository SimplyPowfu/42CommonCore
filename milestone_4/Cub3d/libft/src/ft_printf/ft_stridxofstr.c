/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stridxofstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:54:27 by glancell          #+#    #+#             */
/*   Updated: 2025/03/28 21:29:42 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stridxofstr(const char *str, char *find)
{
	int		i;
	size_t	j;
	size_t	find_len;

	if (!str || !find)
		return (-1);
	find_len = ft_strlen(find);
	if (find_len == 0)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (find[j] && find[j] == str[i + j])
			j++;
		if (j == find_len)
			return (i);
		i++;
	}
	return (-1);
}
