/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 07:58:22 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/07 08:01:57 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"
#include "../mlx/mlx.h"

void	put_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->background, x, y);
			x += IMG_W;
		}
		y += IMG_H;
	}
}

void	put_tree(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img->tree,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
}

void	put_player(t_data *data)
{
	data->p_x = data->map->x;
	data->p_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->win, data->img->player_up,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
}

void	put_exit(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img->exit,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
}

void	put_pokeball(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img->pokeball,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
}
