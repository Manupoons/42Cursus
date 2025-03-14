NAME = philo

DEF_COLOR = \033[0;39m
BRIGHT_GREEN =	\033[1;92m

SRC = src/main.c src/utils.c src/philo.c src/init.c \
		src/simulation.c src/monitor.c src/error.c src/set_get.c

INC = ./inc/philo_test.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -MMD -I./inc -g

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJS = ${SRC:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRC)))

all: ${NAME}

-include $(DEPS)
${NAME}: ${OBJS}
	@${CC} ${OBJS} -o $(NAME)
	@echo "\n$(BRIGHT_GREEN)Created ${NAME} ✓$(DEF_COLOR)\n"

clean:
	@${RM} ${OBJS} ${DEPS}
	@echo "\n$(BRIGHT_GREEN)All objects cleaned successfully ✓$(DEF_COLOR)\n"

fclean:
	@${RM} ${OBJS} ${DEPS} ${NAME}
	@echo "\n$(BRIGHT_GREEN)All objects and executable cleaned successfully ✓$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
