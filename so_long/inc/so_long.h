/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:19:02 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/04 18:02:39 by mamaratr         ###   ########.fr       */
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

void	window_size(t_data *data, char **argv);
int		key_press(int key, t_data *data);
void	find_player(t_data *data);
void	put_background(t_data *data);
void	create_map(t_data *data);
void	free_double_p(char ***str);
void	free_double_pointer(t_data *data);
void	calloc_fail(char *str);
void	handle_error(t_data *data, char *str);
int		ft_exit(t_data *data);
void	ft_winner(t_data *data);

void	ft_putstr_fd(char *s, int fd);
void	ft_init(t_data *data, t_map *map);
void	check_path(t_data *data);
void	validate_map(t_data *data, char **argv, int argc);

int		ft_putstr(char	*str);
int		ft_printf(char const *s, ...);
int		ft_putnbr(int num);

#endif
