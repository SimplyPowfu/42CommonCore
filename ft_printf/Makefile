NAME = libftprintf.a
LIBFT = libft/libft.a
LIBFTDIR = libft/
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT)
	@ cp $(LIBFT) $(NAME)
	@ar rcs $(NAME)

$(LIBFT): 
	@$(MAKE) bonus -C $(LIBFTDIR)

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFTDIR)