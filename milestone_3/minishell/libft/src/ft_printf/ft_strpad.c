/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:50:59 by glancell          #+#    #+#             */
/*   Updated: 2025/03/28 21:29:42 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpad(char *s, char c, int n, bool start)
{
	int		s_len;
	char	*res;

	s_len = ft_istrlen(s);
	if (s_len > n || n < 0)
		n = s_len;
	res = ft_calloc(n + 1, sizeof(char));
	if (start)
	{
		ft_memset(res, c, n);
		if (s)
			ft_memcpy(res + (n - s_len), s, s_len);
	}
	else
	{
		if (s)
			ft_memcpy(res, s, s_len);
		ft_memset(res + s_len, c, n - s_len);
	}
	free(s);
	s = res;
	return (res);
}
