CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = minitalk.a
NAME_B = minitalk_bonus.a
LIBFT = libft/libft.a
LIBFTDIR = libft/
CLIENT = client.c
SERVER = server.c
OBJC = ${CLIENT:.c=.o}
OBJS = ${SERVER:.c=.o}
CLIENT_B = client_bonus.c
SERVER_B = server_bonus.c
OBJC_B = ${CLIENT:.c=.o}
OBJS_B = ${SERVER:.c=.o}
COLOR = \033[0;33m

all : $(NAME)

bonus : $(NAME_B)

$(NAME): $(LIBFT) $(OBJC) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(CC) $(CFLAGS) $(CLIENT) -o client $(NAME)
	@$(CC) $(CFLAGS) $(SERVER) -o server $(NAME)
	@clear
	@echo " $(COLOR) mandatory compilato: esegui il server, poi esegui il client dando il PID e il messaggio."

$(NAME_B): $(LIBFT) $(OBJC_B) $(OBJS_B)
	@cp $(LIBFT) $(NAME)
	@$(CC) $(CFLAGS) $(CLIENT_B) -o client $(NAME)
	@$(CC) $(CFLAGS) $(SERVER_B) -o server $(NAME)
	@clear
	@echo " $(COLOR) bonus compilato: esegui il server, poi esegui il client dando il PID e il messaggio."

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) -C $(LIBFTDIR)

%.o: %.c
	@${CC} -c ${CFLAGS} -I. $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@rm -rf $(OBJC) $(OBJC_B) $(OBJS) $(OBJS_B)

fclean: clean
	@rm -rf $(NAME) $(NAME_B) client client_bonus server server_bonus
	@$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all