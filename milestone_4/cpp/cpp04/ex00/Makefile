# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 14:25:51 by ecarbona          #+#    #+#              #
#    Updated: 2025/07/02 16:15:37 by ecarbona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
NAME = animal
SRC = main.cpp animal.cpp dog.cpp cat.cpp wrongAnimal.cpp wrongCat.cpp
OBJ = ${SRC:.cpp=.o}

all : $(NAME)

$(NAME):$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@clear
	@echo "$(NAME) is compiled: run ./$(NAME) without arguments"

bonus:

clean:
	@rm -r $(OBJ)
	@clear

fclean: clean
	@rm -r $(NAME)
	@clear

re: fclean all