/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:33:52 by glancell          #+#    #+#             */
/*   Updated: 2025/03/28 21:29:42 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(unsigned long n, const char *base)
{
	size_t	digit_count;
	int		base_len;
	int		mod;
	char	*res;

	base_len = ft_istrlen(base);
	digit_count = ft_ulnbr_len(n, base_len);
	res = ft_calloc(digit_count + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (digit_count-- > 0)
	{
		mod = n % base_len;
		res[digit_count] = base[mod];
		if (mod < 10)
			res[digit_count] = mod + '0';
		n /= base_len;
	}
	return (res);
}

char	*ft_uitoa(unsigned int n)
{
	return (ft_ultoa_base(n, BASE10));
}

char	*ft_itohex(unsigned long n)
{
	return (ft_ultoa_base(n, BASE16));
}
