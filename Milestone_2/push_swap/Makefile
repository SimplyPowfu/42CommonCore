CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap.a
ANAME = push_swap
LIBFT = libft/libft.a
LIBFTDIR = libft/
SRC = push_swap.c swap_utils.c free.c sort_in_b.c operations/push.c operations/reverse.c operations/rotate.c operations/swap.c
OBJ = ${SRC:.c=.o}

all : $(NAME)
	@$(CC) $(CFLAGS) $(SRC) $(NAME) -o "push_swap" -g

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)
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
	@rm -rf $(NAME) $(ANAME)
	@$(MAKE) fclean -C $(LIBFTDIR)
	@clear

re: fclean all