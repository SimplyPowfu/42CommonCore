/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:48:36 by ecarbona          #+#    #+#             */
/*   Updated: 2024/12/01 19:32:55 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*store(char *buffer, ssize_t bytes_read) //store
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	while (bytes_read != 0)
	{
		str = ft_memcpy(str, buffer);
		return (str);
	}
	return (str);
}

char	*get_next_line(int fd) //read
{
	static char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	char *string;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//buffer = malloc(sizeof(BUFFER_SIZE));
	// if (!buffer)
	// 	return (NULL);
	bytes_read = read(fd, buffer, sizeof(buffer));
	string = buffer;
	return (string);
}

int main()
{
	int	fd = open("filefd.txt", O_RDONLY);
	printf("%d\n", fd);
	printf("%s", get_next_line(fd));
}