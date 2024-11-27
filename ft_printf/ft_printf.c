/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:39:15 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/27 14:45:50 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_arg(const char *input, va_list *arg, int *i, int *len)
{
	if (input[*i] != '%')
		return (0);
	if (input[*i + 1] == 'c')
		*len += ft_putchar_fd(va_arg(*arg, int), 1);
	else if (input[*i + 1] == 's')
		*len += ft_putstr_fd(va_arg(*arg, char *), 1);
	else if (input[*i + 1] == 'p')
		*len += ft_putbase_long((unsigned long)va_arg(*arg, void *));
	else if (input[*i + 1] == 'd' || input[*i + 1] == 'i')
		*len += ft_putnbr_fd(va_arg(*arg, int));
	else if (input[*i + 1] == 'u')
		*len += ft_putnbr_un(va_arg(*arg, int));
	else if (input[*i + 1] == 'x')
		*len += ft_putbase(va_arg(*arg, unsigned int), "0123456789abcdef");
	else if (input[*i + 1] == 'X')
		*len += ft_putbase(va_arg(*arg, unsigned int), "0123456789ABCDEF");
	else if (input[*i + 1] == '%')
		*len += ft_putchar_fd('%', 1);
	return ((*i)++, 1);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(arg, input);
	while (input[++i])
	{
		if (ft_check_arg(input, &arg, &i, &len) == 0)
		{
			write(1, &input[i], 1);
			len++;
		}
	}
	va_end(arg);
	return (len);
}
// int main()
// {
// 	int x = -42;
//     int *p = &x;
//     printf("%d\n", printf("%c\n", 'c'));
// 	ft_printf("%d\n", ft_printf("%c\n", 'c'));
// 	printf("%d\n", printf("%s\n", "ciao"));
// 	ft_printf("%d\n", ft_printf("%s\n", "ciao"));
// 	printf("%d\n", printf("%p\n", p));
// 	ft_printf("%d\n", ft_printf("%p\n", p));
// 	printf("%d\n", printf("%d\n", 42424242));
// 	ft_printf("%d\n", ft_printf("%d\n", 42424242));
// 	printf("%d\n", printf("%i\n", 42424242));
// 	ft_printf("%d\n", ft_printf("%i\n", 42424242));
// 	printf("%d\n", printf("%u\n", 42424242));
// 	ft_printf("%d\n", ft_printf("%u\n", 42424242));
// 	printf("%d\n", printf("%x\n", 42424242));
// 	ft_printf("%d\n", ft_printf("%x\n", 42424242));
// 	printf("%d\n", printf("%X\n", 42424242));
// 	ft_printf("%d\n", ft_printf("%X\n", 42424242));
// 	printf("%d\n", printf("%%42\n"));
// 	ft_printf("%d\n", ft_printf("%%42\n"));
//     return 0;
// }