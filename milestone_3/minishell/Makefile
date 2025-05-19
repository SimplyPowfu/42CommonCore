# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 23:20:38 by glancell          #+#    #+#              #
#    Updated: 2025/04/07 16:24:11 by ecarbona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = minishell
LIBFT   = libft.a

LFT_PATH = ./libft/
INCLUDES = ./include/
SRCDIR   = ./src/
OBJDIR   = objs/


SRC      =	$(SRCDIR)testshell.c $(SRCDIR)Builtns/echo.c $(SRCDIR)Builtns/env.c $(SRCDIR)Builtns/pwd.c \
			$(SRCDIR)Parsing/init.c $(SRCDIR)Parsing/parsing.c \
			$(SRCDIR)Signal/signal.c

OBJ      = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

CC       = cc
CFLAGS   = -Wall -Wextra -Werror
CFINC    = -I$(INCLUDES) -I$(LFT_PATH)

RM       = rm -f
ARCHIVE  = ar rc $(LIBFT)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "Generating $(NAME) executable..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LFT_PATH) -lft -lreadline -g
	@echo "$(NAME) created!"

bonus:

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)/$(dir $*)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -g -c $(CFINC) $< -o $@
	@echo "$< compiled"

$(LIBFT):
	@make -C $(LFT_PATH)

clean:
	@echo "Cleaning object files..."
	$(RM) -rf $(OBJDIR)
	@echo "Objects deleted"

fclean: clean
	@echo "Cleaning $(NAME) and libraries..."
	$(RM) $(NAME) $(NAME)_bonus
	@make fclean -C $(LFT_PATH)
	@echo "Library and $(NAME) deleted!"

re: fclean all
	@echo "Rebuilding everything..."

.PHONY: clean fclean all re bonus