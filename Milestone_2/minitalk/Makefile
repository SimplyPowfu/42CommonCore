CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = minitalk.a
LIBFT = libft/libft.a
LIBFTDIR = libft/
CLIENT = client.c
SERVER = server.c
OBJC = ${CLIENT:.c=.o}
OBJS = ${SERVER:.c=.o}
COLOR = \033[0;33m

all : $(NAME)

$(NAME): $(LIBFT) $(OBJC) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(CC) $(CFLAGS) $(CLIENT) -o client $(NAME)
	@$(CC) $(CFLAGS) $(SERVER) -o server $(NAME)
	@clear
	@echo " $(COLOR) mandatory compilato: esegui il server, poi esegui il client dando il PID e il messaggio."

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) -C $(LIBFTDIR)

%.o: %.c
	@${CC} -c ${CFLAGS} -I. $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@rm -rf $(OBJC) $(OBJS)

fclean: clean
	@rm -rf $(NAME) client server
	@$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all