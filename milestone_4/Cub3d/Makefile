# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 23:20:38 by glancell          #+#    #+#              #
#    Updated: 2025/06/16 15:53:04 by ecarbona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3d
NAME_BONUS = cub3d_bonus
LIBFT   = libft.a

LFT_PATH = ./libft/
INCLUDES = ./include/
SRCDIR   = ./src/
OBJDIR   = objs/

MLX = minilibx-linux/libmlx.a
MLX_DIR = minilibx-linux

SRC      =	$(SRCDIR)main.c \
			$(SRCDIR)Engine/Raycasting/Raycasting.c $(SRCDIR)Engine/Raycasting/calc.c \
			$(SRCDIR)Engine/minimap_bonus.c $(SRCDIR)Engine/kick_and_hud.c $(SRCDIR)Engine/draw.c \
			$(SRCDIR)Key_binding/key_press_bonus.c $(SRCDIR)Key_binding/movements_bonus.c $(SRCDIR)Key_binding/rotation_bonus.c $(SRCDIR)Key_binding/toggle_stuffs.c \
			$(SRCDIR)Parsing/validating.c $(SRCDIR)Parsing/validating_data.c \
			$(SRCDIR)Utils/free.c $(SRCDIR)Utils/utils_valid.c $(SRCDIR)Utils/utils.c $(SRCDIR)Utils/norm.c $(SRCDIR)Utils/norm2.c\

OBJ      = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

CC       = cc
CFLAGS   = -Wall -Wextra -Werror
CFINC    = -I$(INCLUDES) -I$(LFT_PATH)

RM       = rm -f
ARCHIVE  = ar rc $(LIBFT)

all: $(MLX) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "Generating $(NAME) executable..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LFT_PATH) $(MLX) -lft -lX11 -lXext -lm
	@clear
	@echo "$(NAME) created!"

bonus: $(MLX) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ) $(LIBFT)
	@echo "Generating $(NAME_BONUS) executable..."
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ) -L$(LFT_PATH) $(MLX) -lft -lX11 -lXext -lm
	@clear
	@echo "$(NAME_BONUS) created!"


$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)/$(dir $*)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -g -c $(CFINC) $< -o $@
	@echo "$< compiled"

$(LIBFT):
	@make -C $(LFT_PATH)

$(MLX):
	@if [ ! -d $(MLX_DIR) ]; then \
		echo "Cloning MiniLibX..."; \
		git clone git@github.com:42paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@echo "Building MiniLibX..."
	@make -C $(MLX_DIR)

clean:
	@echo "Cleaning object files..."
	$(RM) -rf $(OBJDIR)
	@clear
	@echo "Objects deleted"

fclean: clean
	@echo "Cleaning $(NAME) and libraries..."
	$(RM) $(NAME) $(NAME)_bonus
	@make fclean -C $(LFT_PATH)
	@clear
	@echo "Library and $(NAME) deleted!"

re: fclean all
	@echo "Rebuilding everything..."

.PHONY: clean fclean all re bonus
