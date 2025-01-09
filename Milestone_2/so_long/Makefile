CC = cc
CFLAGS = -Wall -Wextra -Werror
XMLFLAGS = -Lmlx -lmlx -lXext -lX11 -lm -Lmlx -lmlx -lXext -lX11 -lm
NAME = so_long.a
LIBFT = libft/libft.a
LIBFTDIR = libft/
SRC = mandatory/add_texture.c mandatory/check_map.c mandatory/put_map.c mandatory/so_long.c mandatory/free.c
SRCDIR = mandatory/
BONUS = bonus/add_texture_bonus.c bonus/check_map_bonus.c bonus/put_map_bonus.c bonus/so_long_bonus.c bonus/free_bonus.c
BONUSDIR = bonus/
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${BONUS:.c=.o}
NAME_S = so_long
NAME_B = so_long_bonus
COLOR = \033[0;33m

all: $(NAME)

bonus: $(NAME_B)

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME_S) $(XMLFLAGS) $(NAME)
	@clear
	@echo "$(COLOR) mandatory compilato: esegui so_long"

$(NAME_B): $(LIBFT) $(OBJ_BONUS)
	@cp $(LIBFT) $(NAME)
	@cp $(LIBFT) $(NAME_B)
	@$(CC) $(CFLAGS) $(BONUS) -o $(NAME_B) $(XMLFLAGS) $(NAME)
	@clear
	@echo "$(COLOR) bonus compilato: esegui so_long_bonus"

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) -C $(LIBFTDIR)

%.o: %.c
	@${CC} -c ${CFLAGS} -I. $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -rf $(NAME) $(NAME_S) $(NAME_B)
	@$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all
