/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:48:36 by glancell          #+#    #+#             */
/*   Updated: 2025/05/30 14:16:47 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read(int fd, char **str, char *buffer)
{
	int		bytes_read;
	char	*tmp;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0 || buffer == NULL)
	{
		free(*str);
		*str = NULL;
		return (-1);
	}
	if (bytes_read == 0)
		return (bytes_read);
	tmp = ft_strjoin(*str, buffer);
	free (*str);
	*str = tmp;
	return (bytes_read);
}

static void	get_result(char **str, char **result)
{
	size_t	i;
	size_t	len;
	char	*diff;

	diff = ft_strchr(*str, '\n');
	len = ft_strlen(*str) - ft_strlen(diff) + 2;
	*result = malloc(len);
	if (!result)
		return ;
	i = 0;
	while (i < len - 1)
	{
		(*result)[i] = (*str)[i];
		i++;
	}
	(*result)[i] = '\0';
}

static void	del_string(char **str)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	if (!ft_strchr(*str, '\n'))
	{
		free(*str);
		*str = NULL;
		return ;
	}
	tmp = malloc((ft_strlen(ft_strchr(*str, '\n'))) * sizeof(char));
	if (!tmp)
		return ;
	i = 0;
	j = ft_strlen(*str) - ft_strlen(ft_strchr(*str, '\n')) + 1;
	while (j < ft_strlen(*str))
		tmp[i++] = (*str)[j++];
	tmp[i] = '\0';
	free(*str);
	*str = tmp;
	if (**str == 0)
	{
		free(*str);
		*str = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*string[4096];
	char		*result;
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (string[fd] == NULL)
		string[fd] = ft_strdup("");
	bytes_read = 1;
	while (ft_strchr(string[fd], '\n') == NULL && bytes_read > 0)
		bytes_read = ft_read(fd, &string[fd], buffer);
	free(buffer);
	if (bytes_read == -1)
		return (NULL);
	if (ft_strlen(string[fd]) == 0)
		return (free(string[fd]), NULL);
	get_result(&string[fd], &result);
	del_string(&string[fd]);
	return (result);
}
