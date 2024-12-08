/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:19:02 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/08 18:01:04 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include "../src/Libft/libft.h"

# define IMG_W 50
# define IMG_H 50
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*background;
	void	*exit;
	void	*pokeball;
	void	*tree;
}	t_img;

typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		pokeballs;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
}	t_data;

//so_long
int		ft_exit(t_data *data);
void	check_map_ext(char *file_name);

//check_path
int		valid_exit(t_data *data, int x, int y, char **visited);
int		valid_collectibles(t_data *data, int x, int y, char **visited);
void	check_collectibles_path(t_data *data, int x, int y);
void	check_path(t_data *data);

//initializer
void	window_size(t_data *data, char **argv);
void	ft_init(t_data *data, t_map *map);

//validate_map
void	validate_map(t_data *data, char **argv, int argc);

//key_press
int		key_press(int key, t_data *data);
void	ft_move(t_data *data, char pos, int dir);
void	ft_winner(t_data *data);

//ft_utils
void	find_player(t_data *data);
void	free_double_p(char ***str);
void	free_double_pointer(t_data *data);
void	calloc_fail(char *str);
void	handle_error(t_data *data, char *str);

//create map
void	create_map(t_data *data);

//put_assets
void	put_background(t_data *data);
void	put_tree(t_data *data);
void	put_player(t_data *data);
void	put_exit(t_data *data);
void	put_pokeball(t_data *data);

//ft_putnbr
void	ft_putstr_fd(char *s, int fd);
int		ft_putnbr(int num);
char	*ft_itoa(int n);
size_t	ft_numsize(long num);

//ft_printf
int		ft_printf(char const *s, ...);
int		ft_convert(va_list v1, const char s);
int		ft_putstr(char *str);
int		ft_putchar(char c);

#endif
