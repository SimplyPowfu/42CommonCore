# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 16:39:41 by ecarbona          #+#    #+#              #
#    Updated: 2025/03/23 18:51:14 by ecarbona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = minishell
SRC = testshell.c
OBJ = ${SRC:.c=.o}
COLOR = \033[1;32m

all : $(NAME)

$(NAME): $(OBJ) 
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) -lreadline
	@clear
	@echo "$(COLOR) mandatory compilato: esegui ./minishell "

bonus:

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@clear

fclean: clean
	@rm -rf $(NAME) $(ANAME) $(BNAME)
	@clear

re: fclean all