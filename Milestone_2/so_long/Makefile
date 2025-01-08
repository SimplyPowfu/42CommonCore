CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long.a
LIBFT = libft/libft.a
LIBFTDIR = libft/
SRC = mandatory/add_texture.c mandatory/check_map.c mandatory/put_map.c mandatory/so_long.c
SRCDIR = mandatory/
BONUS = bonus/add_texture_bonus.c bonus/check_map_bonus.c bonus/put_map_bonus.c bonus/so_long_bonus.c bonus/free_bonus.c
BONUSDIR = bonus/
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${BONUS:.c=.o}

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) -C $(LIBFTDIR)

bonus: $(OBJ) $(OBJ_BONUS)
	@ar rc $(NAME) $(OBJ_BONUS) $(OBJ)

%.o: %.c
	@${CC} -c ${CFLAGS} -I. $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all
