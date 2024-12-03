/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:36 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/03 11:25:12 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

static void	ft_player_move(t_data *data, char pos, int dir)
{
	if (pos == 'y' && dir == UP)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_up,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
	if (pos == 'x' && dir == LEFT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_left,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
	if (pos == 'y' && dir == DOWN)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_down,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
	if (pos == 'x' && dir == RIGHT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_right,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
}

static void	ft_collect(t_data *data, char pos, int dir)
{
	data->collected++;
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
		|| data->collected != data->map->pokeballs))
		data->p_y = data->p_y + 1 * dir;
	else if (pos == 'x' && data->map->map[data->p_y][data->p_x + 1 * dir] != '1'
		&& (data->map->map[data->p_y][data->p_x + 1 * dir] != 'E'
		|| data->collected != data->map->pokeballs))
		data->p_x = data->p_x + 1 * dir;
	else if (pos == 'y' && data->map->map[data->p_y + 1 * dir][data->p_x] == 'E'
		&& data->collected != data->map->pokeballs)
		write(1, "Collect all collectibles before leaving\n", 40);
	else if (pos == 'y' && data->map->map[data->p_y][data->p_x + 1 * dir] == 'E'
		&& data->collected != data->map->pokeballs)
		write(1, "Collect all collectibles before leaving\n", 40);
	ft_player_move(data, pos, dir);
	if (data->map->map[data->p_y][data->p_x] == 'C')
		ft_collect(data, pos, dir);
	mlx_do_sync(data->mlx);
	ft_printf("You moved &d times\n", ++data->counter);
}

int	key_press(int key, t_data *data)
{
	if (key == ESC)
		ft_exit(data);
	else if (key == W || key == UARROW)
		ft_move(data, 'y', UP);
	else if (key == A || key == LARROW)
		ft_move(data, 'x', LEFT);
	else if (key == S || key == DARROW)
		ft_move(data, 'y', DOWN);
	else if (key == D || key == RARROW)
		ft_move(data, 'x', RIGHT);
	if (data->map->map[data->p_y][data->p_x] == 'E')
		ft_winner(data);
	return (0);
}
