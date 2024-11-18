NAME = push_swap

SRC = src/*.c
OBJ := $(SRC:%.c=%.o)

CC = gcc
RM = rm -f
FLAGS = -Werror -Wextra -Wall

$(NAME):
	$(CC) $(FLAGS) $(SRC) -Iinc -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
