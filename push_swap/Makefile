NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g
RM = rm -f

SRCS = src/moves/pa.c \
		src/moves/pb.c \
		src/moves/ra.c \
		src/moves/rb.c \
		src/moves/rr.c \
		src/moves/rra.c \
		src/moves/rrb.c \
		src/moves/rrr.c \
		src/moves/sa.c \
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

OBJS = $(SRCS:.c=.o)

INCLUDES = push_swap.h

all: $(NAME)
	@echo "ok"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "fully cleaned"

re: fclean all

.PHONY: all clean fclean re