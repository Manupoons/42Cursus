/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:36 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/11 09:16:51 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

static void	ft_player_move(t_data *data, char pos, int dir, int exit)
{
	if (pos == 'y' && dir == UP)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_back,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	if (pos == 'x' && dir == LEFT)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_left,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	if (pos == 'y' && dir == DOWN)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_front,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	if (pos == 'x' && dir == RIGHT)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_right,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	if (pos == 'y' && dir == UP && exit == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->p_back_exit,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	if (pos == 'x' && dir == LEFT && exit == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->p_left_exit,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	if (pos == 'y' && dir == DOWN && exit == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->p_front_exit,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	if (pos == 'x' && dir == RIGHT && exit == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->p_right_exit,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
}

static void	ft_collect(t_data *data)
{
	data->collected++;
	ft_printf("\nCoins collected: %d \n", data->collected);
	data->map->map[data->p_y][data->p_x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->p_x * IMG_W), (data->p_y * IMG_H));
}

static int	ft_try_move(t_data *data, char pos, int dir)
{
	if (pos == 'y' && data->map->map[data->p_y + dir][data->p_x] != '1'
		&& (data->map->map[data->p_y + dir][data->p_x] != 'E'
			|| data->collected == data->map->coins))
	{
		data->p_y += dir;
		return (0);
	}
	if (pos == 'x' && data->map->map[data->p_y][data->p_x + dir] != '1'
		&& (data->map->map[data->p_y][data->p_x + dir] != 'E'
			|| data->collected == data->map->coins))
	{
		data->p_x += dir;
		return (0);
	}
	if ((pos == 'y' && data->map->map[data->p_y + dir][data->p_x] == 'E')
		|| (pos == 'x' && data->map->map[data->p_y][data->p_x + dir] == 'E'))
	{
		ft_printf("\nCollect all collectibles before leaving\n");
		if (pos == 'y')
			data->p_y += dir;
		else
			data->p_x += dir;
		return (1);
	}
	return (0);
}

void	ft_move(t_data *data, char pos, int dir)
{
	int	prev_x;
	int	prev_y;
	int	exit;

	prev_x = data->p_x;
	prev_y = data->p_y;
	exit = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(prev_x * IMG_W), (prev_y * IMG_H));
	exit = ft_try_move(data, pos, dir);
	if (data->map->map[prev_y][prev_x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit,
			(prev_x * IMG_W), (prev_y * IMG_H));
	if (data->map->map[data->p_y][data->p_x] == 'C')
		ft_collect(data);
	ft_player_move(data, pos, dir, exit);
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
			data->collected == data->map->coins)
	{
		mlx_destroy_window(data->mlx, data->win);
		ft_printf("\nCongratulations!!\nYou won in %d moves\n", data->counter);
		free_data(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
