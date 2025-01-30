CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap.a
LIBFT = libft/libft.a
LIBFTDIR = libft/
SRC = 
OBJ = ${SRC:.c=.o}
COLOR = \033[0;33m #giallo

all : $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@clear
	@echo " $(COLOR) push_swap"

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) -C $(LIBFTDIR)

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