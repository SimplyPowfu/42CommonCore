# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 16:39:41 by ecarbona          #+#    #+#              #
#    Updated: 2025/03/24 15:20:24 by ecarbona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g
NAME = minishell
LIBFT = libft/libft.a
LIBFTDIR = libft/
SRC = testshell.c
OBJ = ${SRC:.c=.o}
COLOR = \033[1;32m

all : $(NAME)

$(NAME): $(LIBFT) $(OBJ) 
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME) -lreadline
	@clear
	@echo "$(COLOR) mandatory compilato: esegui ./minishell "

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) bonus -C $(LIBFTDIR)

bonus:

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@clear

fclean: clean
	@rm -rf $(NAME) $(ANAME) $(BNAME)
	@rm -rf $(NAME) $(ANAME) $(BNAME)
	@clear

re: fclean all