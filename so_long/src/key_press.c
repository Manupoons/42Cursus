/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:36 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/09 12:20:47 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

void	ft_winner(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("\nCongratulations!!\nYou won in %d moves\n", data->counter);
	free_double_pointer(data);
	exit(EXIT_SUCCESS);
}

static void	ft_player_move(t_data *data, char pos, int dir)
{
	if (pos == 'y' && dir == UP)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_up,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	if (pos == 'x' && dir == LEFT)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_left,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	if (pos == 'y' && dir == DOWN)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_down,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	if (pos == 'x' && dir == RIGHT)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_right,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
}

static void	ft_collect(t_data *data, char pos, int dir)
{
	data->collected++;
	ft_printf("\nPokeballs collected: %d \n", data->collected);
	data->map->map[data->p_y][data->p_x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->p_x * IMG_W), (data->p_y * IMG_H));
	ft_player_move(data, pos, dir);
}

void	ft_move(t_data *data, char pos, int dir)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->p_x * IMG_W), (data->p_y * IMG_H));
	if (pos == 'y' && data->map->map[data->p_y + 1 * dir][data->p_x] != '1'
		&& (data->map->map[data->p_y + 1 * dir][data->p_x] != 'E'
			|| data->collected == data->map->pokeballs))
		data->p_y = data->p_y + 1 * dir;
	else if (pos == 'x' && data->map->map[data->p_y][data->p_x + 1 * dir] != '1'
		&& (data->map->map[data->p_y][data->p_x + 1 * dir] != 'E'
			|| data->collected == data->map->pokeballs))
		data->p_x = data->p_x + 1 * dir;
	else if ((pos == 'y' || pos == 'x')
		&& (data->map->map[data->p_y + 1 * dir][data->p_x] == 'E'
		|| data->map->map[data->p_y][data->p_x + 1 * dir] == 'E')
		&& data->collected != data->map->pokeballs)
		write(1, "\nCollect all collectibles before leaving\n", 41);
	ft_player_move(data, pos, dir);
	if (data->map->map[data->p_y][data->p_x] == 'C')
		ft_collect(data, pos, dir);
	mlx_do_sync(data->mlx);
	ft_printf("\nYou moved %d times\n", ++data->counter);
}

int	key_press(int key, t_data *data)
{
	if (key == ESC)
		ft_exit(data);
	else if (key == W)
		ft_move(data, 'y', UP);
	else if (key == A)
		ft_move(data, 'x', LEFT);
	else if (key == S)
		ft_move(data, 'y', DOWN);
	else if (key == D)
		ft_move(data, 'x', RIGHT);
	if (data->map->map[data->p_y][data->p_x] == 'E' &&
			data->collected == data->map->pokeballs)
		ft_winner(data);
	return (0);
}
