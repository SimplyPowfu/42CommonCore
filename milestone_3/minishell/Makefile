# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glancell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 23:20:38 by glancell          #+#    #+#              #
#    Updated: 2025/05/17 20:30:44 by glancell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = minishell
LIBFT   = libft.a

LFT_PATH = ./libft/
INCLUDES = ./include/
SRCDIR   = ./src/
OBJDIR   = objs/


SRC      =	$(SRCDIR)main.c \
			$(SRCDIR)Pipes/executioner.c $(SRCDIR)Pipes/switcher.c $(SRCDIR)Pipes/hadler_process.c $(SRCDIR)Pipes/hadler_process_utility.c $(SRCDIR)Pipes/pipeline_exe.c\
			$(SRCDIR)Redirections/redirections.c $(SRCDIR)Redirections/here_doc.c $(SRCDIR)Parsing/syntax.c\
			$(SRCDIR)Builtns/echo.c $(SRCDIR)Builtns/env.c $(SRCDIR)Builtns/pwd.c $(SRCDIR)Builtns/cd.c $(SRCDIR)Builtns/unset.c $(SRCDIR)Builtns/export.c $(SRCDIR)Builtns/export_utils.c $(SRCDIR)Builtns/exit.c \
			$(SRCDIR)Parsing/init.c $(SRCDIR)Parsing/init1.c $(SRCDIR)Parsing/parsing.c $(SRCDIR)Parsing/pars_init.c $(SRCDIR)Parsing/redir.c $(SRCDIR)Parsing/redir1.c $(SRCDIR)Parsing/pars_redir.c $(SRCDIR)Parsing/pars_pip.c \
			$(SRCDIR)Signal/signal.c $(SRCDIR)Signal/signal1.c\
			$(SRCDIR)Utils/dollar_utils.c $(SRCDIR)Utils/utils.c $(SRCDIR)Utils/utils1.c $(SRCDIR)Utils/utils2.c $(SRCDIR)Utils/utils3.c $(SRCDIR)Utils/free.c \
			$(SRCDIR)Pipes/pipe_exe_uti.c $(SRCDIR)Pipes/here_doc_pip.c\

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
	@clear
	@echo "$(NAME) created!"

#bonus:

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)/$(dir $*)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -g -c $(CFINC) $< -o $@
	@echo "$< compiled"

$(LIBFT):
	@make -C $(LFT_PATH)

clean:
	@echo "Cleaning object files..."
	@$(RM) -rf $(OBJDIR)
	@clear
	@echo "Objects deleted"

fclean: clean
	@echo "Cleaning $(NAME) and libraries..."
	@$(RM) $(NAME) $(NAME)_bonus
	@make fclean -C $(LFT_PATH)
	@clear
	@echo "Library and $(NAME) deleted!"

re: fclean all
	@echo "Rebuilding everything..."

.PHONY: clean fclean all re bonus