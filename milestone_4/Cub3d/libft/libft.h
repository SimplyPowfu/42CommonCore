/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:27:52 by glancell          #+#    #+#             */
/*   Updated: 2025/03/29 18:48:57 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"

# define PF_ARGS_WHITELIST " .+-#0123456789"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef enum e_pftype
{
	PF_ESCAPE,
	PF_UNKNOWN,
	PF_INT,
	PF_UINT,
	PF_CHAR,
	PF_STR,
	PF_HEX,
	PF_POINTER
}	t_pftype;

typedef struct s_pfflag
{
	char		*flag;

	char		*res;
	int			reslen;
	bool		zero;
	bool		minus;

	size_t		llen;
	size_t		rlen;

	t_pftype	type;

	int			width;

	int			prec;
	bool		wprec;

	bool		isupper;
	bool		convert;

	bool		wplus;
	bool		wminus;
	bool		wspaces;
	bool		wzeros;
}	t_pfflag;

int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
char			*get_next_line(int fd);
int				ft_printf(const char *str, ...);
size_t			pf_handlebonus(t_pfflag flag);
t_pfflag		pf_getflag(char *f);
size_t			pf_handle_bonus_end(t_pfflag flag);
size_t			pf_handle_bonus_start(t_pfflag flag);
char			*ft_getaddr(void *p);
int				ft_istrlen(const char *s);
char			*ft_itohex(unsigned long n);
int				ft_ulnbr_len(unsigned long n, int base_len);
char			*ft_strpad(char *s, char c, int n, bool start);
char			*ft_strtoupper(char *s);
char			*ft_uitoa(unsigned int n);
char			*ft_ultoa_base(unsigned long n, const char *base);
char			**ft_free_split(char **tab);
int				is_valid_int(char *str);
unsigned int	ft_abs(int n);
int				ft_strcmp(const char *s1, const char *s2);

#endif