CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long.a
SRC = test.c add_texture.c put_map.c check_map.c
SRC_BONUS = 
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	ar rc $(NAME) $(OBJ_BONUS) $(OBJ)

%.o: %.c
	${CC} -c ${CFLAGS} -I. $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
