NAME = push_swap

SRC = src/moves/sa.c \
		src/moves/pa.c \
		src/moves/pb.c \
		src/moves/ra.c \
		src/moves/rb.c \
		src/moves/rr.c \
		src/moves/rra.c \
		src/moves/rrb.c \
		src/moves/rrr.c \
		src/sort/get_cheapest.c \
		src/sort/get_target.c \
		src/sort/push_cheapest.c \
		src/sort/size_info.c \
		src/sort/sort.c \
		src/sort/utils.c \
		src/utils/errors_check.c \
		src/utils/ft_atoi.c \
		src/utils/ft_split.c \
		src/utils/ft_strdup.c \
		src/utils/ft_strjoin.c \
		src/utils/ft_strlcpy.c \
		src/utils/ft_strncmp.c \
		src/utils/ft_substr.c \
		src/utils/ps_utils.c \
		src/utils/utils.c \
		src/utils/validate_input.c \
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
