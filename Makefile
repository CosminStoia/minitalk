CFLAGS = -Wall -Wextra -Werror

CLIENT_SRC = client.c
SERVER_SRC = server.c


CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)


all: client server

client: $(CLIENT_OBJ)
	cc $(CFLAGS) $(CLIENT_OBJ) -o $@

server: $(SERVER_OBJ)
	CC $(CFLAGS) $(SERVER_OBJ) -o $@

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re