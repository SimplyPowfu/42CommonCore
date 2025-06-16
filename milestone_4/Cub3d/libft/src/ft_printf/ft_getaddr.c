/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:52:12 by glancell          #+#    #+#             */
/*   Updated: 2025/03/28 21:29:42 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getaddr(void *p)
{
	char			*res;
	const uintptr_t	p_addr = (uintptr_t) p;
	size_t			addr_len;
	char			*itohex;

	if (p_addr == 0)
		return (ft_strdup("(nil)"));
	addr_len = ft_ulnbr_len(p_addr, 16) + 3;
	res = ft_calloc(addr_len, sizeof(char));
	res[0] = '0';
	res[1] = 'x';
	itohex = ft_itohex(p_addr);
	ft_strlcat(res, itohex, addr_len);
	free(itohex);
	return (res);
}
