/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:31:29 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/11 12:51:55 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

static void	ft_player_move_y(t_data *data, int dir)
{
	int	on_exit;

	on_exit = (data->map->map[data->p_y][data->p_x] == 'E');
	if (dir == UP)
	{
		if (on_exit)
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->p_back_exit, (data->p_x * IMG_W),
				(data->p_y * IMG_H));
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->player_back, (data->p_x * IMG_W),
				(data->p_y * IMG_H));
	}
	if (dir == DOWN)
	{
		if (on_exit)
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->p_front_exit, (data->p_x * IMG_W),
				(data->p_y * IMG_H));
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->player_front, (data->p_x * IMG_W),
				(data->p_y * IMG_H));
	}
}

static void	ft_player_move_x(t_data *data, int dir)
{
	int	on_exit;

	on_exit = (data->map->map[data->p_y][data->p_x] == 'E');
	if (dir == LEFT)
	{
		if (on_exit)
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->p_left_exit, (data->p_x * IMG_W),
				(data->p_y * IMG_H));
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->player_left, (data->p_x * IMG_W),
				(data->p_y * IMG_H));
	}
	if (dir == RIGHT)
	{
		if (on_exit)
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->p_right_exit, (data->p_x * IMG_W),
				(data->p_y * IMG_H));
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->player_right, (data->p_x * IMG_W),
				(data->p_y * IMG_H));
	}
}

void	ft_player_move(t_data *data, char pos, int dir)
{
	if (pos == 'y')
		ft_player_move_y(data, dir);
	if (pos == 'x')
		ft_player_move_x(data, dir);
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

	prev_x = data->p_x;
	prev_y = data->p_y;
	if (data->map->map[prev_y][prev_x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit,
			(prev_x * IMG_W), (prev_y * IMG_H));
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img->background,
			(prev_x * IMG_W), (prev_y * IMG_H));
	ft_try_move(data, pos, dir);
	if (data->map->map[data->p_y][data->p_x] == 'C')
	{
		data->collected++;
		ft_printf("\nCoins collected: %d \n", data->collected);
		data->map->map[data->p_y][data->p_x] = '0';
		mlx_put_image_to_window(data->mlx, data->win, data->img->background,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
	ft_player_move(data, pos, dir);
	mlx_do_sync(data->mlx);
	ft_printf("\nYou moved %d times\n", ++data->counter);
}
