CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap.a
ANAME = push_swap
BNAME = checker
LIBFT = libft/libft.a
LIBFTDIR = libft/
SRC = mandatory/main.c mandatory/push_swap.c mandatory/swap_utils.c mandatory/free.c mandatory/sort_in_b.c mandatory/double_moves.c operations/push.c operations/reverse.c operations/rotate.c operations/swap.c
BONUS = bonus/checker.c
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${BONUS:.c=.o}
COLOR = \033[1;32m

all : $(NAME)
	@$(CC) $(CFLAGS) $(SRC) $(NAME) -o $(ANAME) -g

bonus :	$(NAME) $(OBJ_BONUS)
	@ar rc $(NAME) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(BONUS) $(NAME) -o $(BNAME) -g
	@echo "$(COLOR) bonus compilato: esegui ./checker e aggiungi i valori"

$(NAME): $(LIBFT) $(OBJ) 
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@clear
	@echo "$(COLOR) mandatory compilato: esegui ./push_swap e aggiungi i valori"

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) bonus -C $(LIBFTDIR)

%.o: %.c
	@${CC} -c ${CFLAGS} -I. $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@clear

fclean: clean
	@rm -rf $(NAME) $(ANAME) $(BNAME)
	@$(MAKE) fclean -C $(LIBFTDIR)
	@clear

re: fclean all