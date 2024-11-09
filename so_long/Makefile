NAME := so_long

CC := cc

CFLAGS := -Wall -Werror -Wextra -Iinc/

SRC := src/*.c
GETNL := get_next_line/*.c
LIB := -Lmlx -lmlx -lXext -lX11 -lm
MLX := mlx/

all:
	make -C $(MLX)
	$(CC) $(CFLAGS) $(SRC) $(GETNL) $(LIB) -o $(NAME)

clean:

fclean: clean
	make clean -C $(MLX)
	rm -rf $(NAME)

re: fclean all