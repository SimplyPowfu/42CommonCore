CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap.a
ANAME = push_swap
BNAME = checker
LIBFT = libft/libft.a
LIBFTDIR = libft/
SRC = push_swap.c swap_utils.c free.c sort_in_b.c double_moves.c operations/push.c operations/reverse.c operations/rotate.c operations/swap.c
BONUS = checker.c
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${BONUS:.c=.o}

all : $(NAME)
	@$(CC) $(CFLAGS) $(SRC) $(NAME) -o $(ANAME) -g

bonus :	$(NAME) $(OBJ_BONUS)
	@ar rc $(NAME) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(BONUS) $(NAME) -o $(BNAME) -g

$(NAME): $(LIBFT) $(OBJ) 
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@clear

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) bonus -C $(LIBFTDIR)

%.o: %.c
	@${CC} -c ${CFLAGS} -I. $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@rm -rf $(OBJ)
	@clear

fclean: clean
	@rm -rf $(NAME) $(ANAME) $(BNAME)
	@$(MAKE) fclean -C $(LIBFTDIR)
	@clear

re: fclean all