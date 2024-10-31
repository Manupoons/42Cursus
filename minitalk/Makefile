NAME_SRV = server
NAME_CLT = client

SRV_SRC = server.c

CLT_SRC = client.c

SRV_OBJ := $(SRV_SRC:%.c=%.o)
CLT_OBJ := $(CLT_SRC:%.c=%.o)

CC = gcc
RM = rm -f
FLAGS = -Werror -Wextra -Wall

all: $(SRV_OBJ) $(CLT_OBJ)
		$(CC) $(FLAGS) $(SRV_SRC) -o $(NAME_SRV)
		$(CC) $(FLAGS) $(CLT_SRC) -o $(NAME_CLT)

client: $(CLT_OBJ)
		$(CC) $(FLAGS) $(CLT_SRC) -o $(NAME_CLT)

server: $(SRV_OBJ_OBJ)
		$(CC) $(FLAGS) $(SRV_SRC) -o $(NAME_SRV)

clean:
		$(RM) $(CLT_OBJ) $(SRV_OBJ)

fclean: clean
		$(RM) $(NAME_CLT) $(NAME_SRV)

re: fclean all

.PHONY: all client server clean fclean re
