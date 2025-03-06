# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 17:25:58 by ecarbona          #+#    #+#              #
#    Updated: 2025/03/06 18:19:31 by ecarbona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -g
NAME = philo.a
ANAME = philo
BNAME = philo_bonus
SRC = main.c init.c utils.c
BONUS = 
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${BONUS:.c=.o}
COLOR = \033[1;32m

all : $(NAME)
	@$(CC) $(CFLAGS) $(SRC) $(NAME) -o $(ANAME) -g

bonus :	$(NAME) $(OBJ_BONUS)
	@ar rc $(NAME) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(BONUS) $(NAME) -o $(BNAME) -g
	@echo "$(COLOR) bonus compilato: esegui ./checker e aggiungi i valori"

$(NAME):$(OBJ) 
	@ar rc $(NAME) $(OBJ)
	@clear
	@echo "$(COLOR) mandatory compilato: esegui ./philo e aggiungi i valori"

%.o: %.c
	@${CC} -c ${CFLAGS} -I. $< -o $@

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@clear

fclean: clean
	@rm -rf $(NAME) $(ANAME) $(BNAME)
	@clear

re: fclean all