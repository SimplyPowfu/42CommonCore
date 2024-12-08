/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:48:36 by ecarbona          #+#    #+#             */
/*   Updated: 2024/12/08 21:40:05 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(int fd, char **str, char *buffer)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0 || buffer == NULL)
	{
		//free(*str);
		*str = NULL;
		return (-1);
	}
	if (bytes_read == 0)
		return (bytes_read);
	tmp = ft_strjoin(*str, buffer);
	*str = tmp;
	return (bytes_read);
}

static void	get_result(char **str, char **result)
{
	int		i;
	char	*diff;

	diff = ft_strchr(*str, '\n');
	result = malloc(ft_strlen(*str) - ft_strlen(diff));
	i = 0;
	while(*str[i] != '\n' && *str[i] != '\0')
	{
		*result[i] = *str[i];
		i++;
	}
	*result[i] = '\0';
}

static void	del_string(char **str)
{
	char	*newStatic;
	char	*diff;

	diff = ft_strchr(*str, '\n');
	newStatic = malloc(ft_strlen(diff));
	newStatic = ft_strchr(*str, '\n');
	//newStatic[ft_strlen(newStatic) + 1] = '\0'; 
	//free(*str);
	*str = newStatic;
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*result;
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	bytes_read = 1;
	while (ft_strchr(string, '\n') == NULL && bytes_read > 0)
		bytes_read = ft_read(fd, &string, buffer);
	//free(buffer);
	if (bytes_read == -1)
		return (NULL);
	if (!string)
		return (NULL);
	get_result(&string, &result);
	del_string(&string);
	return (result);
}

int main()
{
	int	fd = open("filefd.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%d\n", fd);
	printf("%s", line);
	//free (line);
	close (fd);
	return (0);
}