CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long.a
LIBFT = libft/libft.a
LIBFTDIR = libft/
SRC = test.c add_texture.c put_map.c check_map.c
OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)

$(LIBFT): $(LIBFTDIR)
	$(MAKE) -C $(LIBFTDIR)

%.o: %.c
	${CC} -c ${CFLAGS} -I. $< -o $@

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all
