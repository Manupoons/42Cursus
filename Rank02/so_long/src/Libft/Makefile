NAME = libft.a

SRC = ft_strlen.c ft_calloc.c ft_strchr.c ft_strncmp.c \
	  ft_strnstr.c ft_atoi.c ft_strjoin.c ft_count_c.c \
	  ft_line_length.c ft_atoi.c ft_strjoin.c ft_count_c.c \
	  ft_count_lines.c get_next_line.c ft_printf.c ft_putnbr.c

LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -fPIC

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJ = ${SRC:.c=.o}

${NAME}: ${OBJ}
	${LIBC} ${NAME} ${OBJ}

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
