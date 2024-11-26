/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:39:15 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/26 17:30:20 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_check_arg(const char *input, va_list arg, int *i)
{
	if (input[*i] != '%')
		return (1);
	if (input[*i + 1] == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1), *i += 1, 0);
	else if (input[*i + 1] == 's')
		return(ft_putstr_fd(va_arg(arg, char*), 1), *i += 1, 0);
	// else if (input[*i + 1] == 'p')
	// 	ft_putstr_fd(va_arg(arg, void *));
	else if (input[*i + 1] == 'd' || input[*i + 1] == 'i')
		return(ft_putnbr_fd(va_arg(arg, int), 1), *i += 1, 0);
	else if (input[*i + 1] == 'u')
		return(ft_putnbr_un(va_arg(arg, int)), *i += 1, 0);
	else if (input[*i + 1] == 'x')
		return(ft_putbase(va_arg(arg, unsigned int),
		"0123456789abcdef"), *i += 1, 0);
	else if (input[*i + 1] == 'X')
		return(ft_putbase(va_arg(arg, unsigned int),
		"0123456789ABCDEF"), *i += 1, 0);
	else if (input[*i + 1] == '%')
		write(1, "%", 1);
	return (*i +=1 , 0);
}

int ft_printf(const char *input, ...)
{
	va_list	arg;
	int		i;

	i = -1;
	va_start(arg, input);
	while (input[++i])
		if (ft_check_arg(input, arg, &i))
			write(1, &input[i], 1);
	va_end(arg);
	return (0);
}

int main()
{
	// int i;
	// i = 011;
	// ft_printf("d:%x \ni:%i\nu:%u\n", 11, i, -2543);
	int x = -42;
    int *p = &x;
    
    // Stampiamo l'indirizzo di p
    printf("%x\n", x);  // (void*) è il tipo generico per puntatori
	ft_printf("%x\n", x);

    return 0;
}