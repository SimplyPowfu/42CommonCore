# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 16:39:41 by ecarbona          #+#    #+#              #
#    Updated: 2025/04/02 18:39:28 by ecarbona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g
NAME = minishell
LIBFT = libft/libft.a
LIBFTDIR = libft/
SRC = main.c init.c testshell.c signal/signal.c 
OBJ = ${SRC:.c=.o}
COLOR = \033[1;32m

all : $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME) -lreadline -g
	@clear
	@echo "$(COLOR) mandatory compilato: esegui ./minishell"

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) bonus -C $(LIBFTDIR)

bonus:

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@clear

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@rm -rf $(NAME) $(ANAME) $(BNAME)
	@clear

re: fclean all