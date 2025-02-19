NAME = push_swap

DEF_COLOR =		\033[0;39m
MAGENTA =		\033[0;95m

SRCS = src/moves/pa.c src/moves/pb.c src/moves/ra.c \
		src/moves/rb.c src/moves/rr.c src/moves/rra.c \
		src/moves/rrb.c src/moves/rrr.c src/moves/sa.c \
		src/sort/get_cheapest.c src/sort/get_target.c \
		src/sort/push_cheapest.c src/sort/size_info.c \
		src/sort/sort.c src/sort/utils.c \
		src/utils/errors_check.c src/utils/stack_manager.c \
		src/push_swap.c src/utils/validate_input.c

INCLUD = ./inc/so_long.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -MMD -I./inc -I./src/Libft -g
LIB = -L. -lm -L./src/Libft -lft

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))

all: ${NAME}

-include $(DEPS)
${NAME}: ${OBJS}
	@echo "\n${MAGENTA}Compiling libft ✓$(DEF_COLOR)\n"
	@make -C ./src/Libft > /dev/null
	@${CC} ${OBJS} $(LIB) -o $(NAME)
	@echo "$(MAGENTA)Created ${NAME} ✓$(DEF_COLOR)\n"

clean:
	@make -C ./src/Libft clean --no-print-directory > /dev/null
	@${RM} ${OBJS} ${DEPS}
	@echo "\n$(MAGENTA)All objects cleaned successfully ✓$(DEF_COLOR)\n"

fclean:
	@make -C ./src/Libft fclean --no-print-directory > /dev/null
	@${RM} ${OBJS} ${DEPS} ${NAME}
	@echo "\n$(MAGENTA)All objects and executable cleaned successfully ✓$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
