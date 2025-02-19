NAME = libft.a

SRC = ft_strlen.c ft_strlcpy.c ft_isdigit.c \
		ft_strdup.c ft_strncmp.c ft_atoi.c ft_substr.c \
		ft_strjoin.c ft_split.c ft_isspace.c\

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
