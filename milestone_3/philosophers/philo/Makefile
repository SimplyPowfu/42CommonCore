# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 17:25:58 by ecarbona          #+#    #+#              #
#    Updated: 2025/03/18 17:53:32 by ecarbona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -g
NAME = philo
SRC = main.c init.c utils.c routine.c free.c
OBJ = ${SRC:.c=.o}
COLOR = \033[1;32m

all : $(NAME)

$(NAME):$(OBJ) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -g
	@clear
	@echo "$(COLOR) mandatory compilato: esegui ./philo e aggiungi i valori"

bonus:

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@clear

fclean: clean
	@rm -rf $(NAME) $(ANAME) $(BNAME)
	@clear

re: fclean all