CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap.a
LIBFT = libft/libft.a
LIBFTDIR = libft/
SRC = free.c operations/push.c operations/reverse.c operations/rotate.c operations/swap.c
OBJ = ${SRC:.c=.o}
COLOR = \033[0;33m #giallo

all : $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)
	@clear
	@echo "$(COLOR)push_swap"

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) bonus -C $(LIBFTDIR)

%.o: %.c
	@${CC} -c ${CFLAGS} -I. $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@rm -rf $(OBJ)
	@clear

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFTDIR)
	@clear

re: fclean all