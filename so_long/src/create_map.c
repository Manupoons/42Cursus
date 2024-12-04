/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:45 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/04 18:10:02 by mamaratr         ###   ########.fr       */
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

void	put_object(t_data *data, char *path)
{
	int	img_w;
	int	img_h;

	data->map->object = mlx_xpm_file_to_image(data->mlx, path,
			&img_w, &img_h);
	if (!data->map->object)
		handle_error(data, "Error\nexit file not found\n");
	mlx_put_image_to_window(data->mlx, data->win, data->map->object,
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

void	create_map(t_data *data)
{
	char	tile;

	data->map->y = 0;
	while (data->map->y < (data->size_y / IMG_H))
	{
		data->map->x = 0;
		while (data->map->x < (data->size_x / IMG_W))
		{
			tile = data->map->map[data->map->y][data->map->x];
			if (tile == 'P')
				put_player(data);
			else if (tile == '1')
				put_object(data, "img/bush.xpm");
			else if (tile == 'C')
				put_object(data, "img/poke.xpm");
			else if (tile == 'E')
				put_exit(data);
			data->map->x++;
		}
		data->map->y++;
	}
}
