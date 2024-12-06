/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:48:34 by ecarbona          #+#    #+#             */
/*   Updated: 2024/12/01 19:12:51 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4
#endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif