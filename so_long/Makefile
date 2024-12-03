NAME = so_long

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

SRCS = ./src/so_long.c ./src/check_path.c ./src/create_map.c ./src/ft_printf.c \
			./src/ft_putnbr.c ./src/ft_utils.c ./src/initializer.c \
			./src/key_press.c ./src/validate_map.c \
			$(wildcard ./src/Libft/*.c)  # Include all .c files from src/Libft

INCLUD = ./inc/so_long.h

CC = gcc
RM = rm -f
AR = ar rc
RN = ranlib
CFLAGS = -Wall -Wextra -Werror -MMD -I./inc -I./src/Libft -g # Add -I for Libft headers
LIB = -L. -lmlx -lXext -lX11 -lm

.c.o:
	@echo "${BLUE} ◎ $(BROWN)Compiling  ${MAGENTA}→  $(CYAN)$< $(DEF_COLOR)"
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))

all:	${NAME}

-include $(DEPS)
${NAME}:	${OBJS}
	@echo "\n${ORANGE}Minilibx compilation $(DEF_COLOR)\n"
	@make -C ./mlx all
	@cp ./mlx/libmlx.a .
	@$(CC) $(SRCS) $(LIB) -o $(NAME)
	@echo "$(GREEN)Created ${NAME} ✓$(DEF_COLOR)\n"


clean:
	@make -C ./mlx clean
	@${RM} ${OBJS}
	@${RM} ${DEPS}
	@echo "\n$(BLUE)All objects cleaned successfully $(DEF_COLOR)\n"

fclean:
	@make -C ./mlx clean
	@${RM} ${OBJS}
	@${RM} ${DEPS}
	@${RM} ${NAME} libmlx.a
	@echo "\n$(BLUE)All objects and executable cleaned successfully$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
