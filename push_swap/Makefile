NAME = push_swap

SRC = $(addprefix src/, push_swap.c)
OBJ := $(SRC:%.c=%.o)

CC = gcc
RM = rm -f
FLAGS = -Werror -Wextra -Wall

all: $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
