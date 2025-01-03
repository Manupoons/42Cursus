NAME = push_swap

SRC = src/moves/*.c \
		src/sort/*.c \
		src/utils/*.c \
		src/push_swap.c

OBJ := $(SRC:.c=.o)

INC = push_swap.h

CC = gcc
RM = rm -f
FLAGS = -Werror -Wextra -Wall -I. -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INC)
	$(CC) %(FLAGS) -c $< -o

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
