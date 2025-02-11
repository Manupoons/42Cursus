NAME = so_long

DEF_COLOR =		\033[0;39m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m

SRCS = ./src/so_long.c ./src/check_path.c ./src/map.c ./src/ft_utils.c \
		./src/initializer.c ./src/key_press.c ./src/put_assets.c \
		./src/player_move.c

INCLUD = ./inc/so_long.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -MMD -I./inc -I./src/Libft
LIB = -L. -lmlx -lXext -lX11 -lm -L./src/Libft -lft

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))

all: ${NAME}

-include $(DEPS)
${NAME}: ${OBJS}
	@echo "\n${YELLOW}Compiling libft ✓$(DEF_COLOR)"
	@make -C ./src/Libft > /dev/null
	@echo "\n${YELLOW}Minilibx compilation ✓$(DEF_COLOR)\n"
	@make -C ./mlx all > /dev/null 2>&1
	@cp ./mlx/libmlx.a .
	@${CC} ${OBJS} $(LIB) -o $(NAME)
	@echo "$(YELLOW)Created ${NAME} ✓$(DEF_COLOR)\n"

clean:
	@make -C ./mlx clean --no-print-directory > /dev/null
	@make -C ./src/Libft clean --no-print-directory > /dev/null
	@${RM} ${OBJS} ${DEPS}
	@echo "\n$(YELLOW)All objects cleaned successfully $(DEF_COLOR)\n"

fclean:
	@make -C ./mlx clean --no-print-directory > /dev/null
	@make -C ./src/Libft fclean --no-print-directory > /dev/null
	@${RM} ${OBJS} ${DEPS} ${NAME} libmlx.a
	@echo "\n$(YELLOW)All objects and executable cleaned successfully $(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
