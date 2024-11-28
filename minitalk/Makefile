NAME_SRV = server
NAME_CLT = client

SRV_SRC = server.c
CLT_SRC = client.c
UTILS_SRC = utils.c

SRVBONUS_SRC = server_bonus.c
CLTBONUS_SRC = client_bonus.c

SRV_OBJ := $(SRV_SRC:.c=.o)
CLT_OBJ := $(CLT_SRC:.c=.o)
UTILS_OBJ := $(UTILS_SRC:.c=.o)

SRVBONUS_OBJ := $(SRVBONUS_SRC:.c=.o)
CLTBONUS_OBJ := $(CLTBONUS_SRC:.c=.o)

CC = gcc
RM = rm -f
FLAGS = -Werror -Wextra -Wall

all: $(SRV_OBJ) $(CLT_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(SRV_OBJ) $(UTILS_OBJ) -o $(NAME_SRV)
	$(CC) $(FLAGS) $(CLT_OBJ) $(UTILS_OBJ) -o $(NAME_CLT)

bonus: $(SRVBONUS_OBJ) $(CLTBONUS_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(SRVBONUS_OBJ) $(UTILS_OBJ) -o $(NAME_SRV)
	$(CC) $(FLAGS) $(CLTBONUS_OBJ) $(UTILS_OBJ) -o $(NAME_CLT)

client: $(CLT_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(CLT_OBJ) $(UTILS_OBJ) -o $(NAME_CLT)

server: $(SRV_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(SRV_OBJ) $(UTILS_OBJ) -o $(NAME_SRV)

clean:
	$(RM) $(CLT_OBJ) $(SRV_OBJ) $(CLTBONUS_OBJ) $(SRVBONUS_OBJ) $(UTILS_OBJ)

fclean: clean
	$(RM) $(NAME_CLT) $(NAME_SRV)

re: fclean all

.PHONY: all client server clean fclean re bonus
