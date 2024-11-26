NAME = libftprintf.a
LIBFT = libft/libft.a
LIBFTDIR = libft/
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

FILE = ft_printf.c ft_putbase.c

OBJ = $(FILE:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)

$(LIBFT): 
	@$(MAKE) bonus -C $(LIBFTDIR)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@rm -rf $(OBJ)
	@clear

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all

run: re
	@clear
	@echo "runnig program..."
	@$(CC) $(FLAGS) ft_printf.c libftprintf.a
	@./a.out

val:	
	@clear
	@echo "runnig program with valgrind..."
	@$(CC) $(FLAGS) ft_printf.c libftprintf.a
	@valgrind --leak-check=yes --track-origins=yes ./a.out