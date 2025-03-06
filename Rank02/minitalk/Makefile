NAME_SRV = server
NAME_CLT = client

SRV_SRC = server.c
CLT_SRC = client.c
UTILS_SRC = utils.c

SRV_OBJ = $(SRV_SRC:.c=.o)
CLT_OBJ = $(CLT_SRC:.c=.o)
UTILS_OBJ = $(UTILS_SRC:.c=.o)

SRVBONUS_SRC = server_bonus.c
CLTBONUS_SRC = client_bonus.c

SRVBONUS_OBJ = $(SRVBONUS_SRC:.c=.o)
CLTBONUS_OBJ = $(CLTBONUS_SRC:.c=.o)

CC = gcc
RM = rm -f
FLAGS = -Werror -Wextra -Wall

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME_SRV) $(NAME_CLT)

$(NAME_SRV): $(SRV_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(SRV_OBJ) $(UTILS_OBJ) -o $(NAME_SRV)

$(NAME_CLT): $(CLT_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(CLT_OBJ) $(UTILS_OBJ) -o $(NAME_CLT)

bonus: $(NAME_SRV)_bonus $(NAME_CLT)_bonus

$(NAME_SRV)_bonus: $(SRVBONUS_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(SRVBONUS_OBJ) $(UTILS_OBJ) -o $(NAME_SRV)

$(NAME_CLT)_bonus: $(CLTBONUS_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(CLTBONUS_OBJ) $(UTILS_OBJ) -o $(NAME_CLT)

clean:
	$(RM) $(SRV_OBJ) $(CLT_OBJ) $(UTILS_OBJ) $(SRVBONUS_OBJ) $(CLTBONUS_OBJ)

fclean: clean
	$(RM) $(NAME_CLT) $(NAME_SRV)

re: fclean all

.PHONY: all clean fclean re bonus
