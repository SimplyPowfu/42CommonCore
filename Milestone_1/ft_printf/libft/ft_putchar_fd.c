/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:20:04 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/27 13:23:59 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
	return (1);
}
// #include <fcntl.h>
// int main()
// {
// 	int fd = open("prova_fd.txt", O_WRONLY);
// 	ft_putchar_fd('c', fd);
// }