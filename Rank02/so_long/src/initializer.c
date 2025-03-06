/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:36:27 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/10 20:07:46 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

static void	ft_set_assests(t_data *data)
{
	int	img_w;
	int	img_h;

	img_w = 50;
	img_h = 50;
	data->img->background = mlx_xpm_file_to_image(data->mlx, "img/Tile.xpm",
			&img_w, &img_h);
	if (!data->img->background)
		handle_error(data, "Error!\nTile file not found\n");
	data->img->exit = mlx_xpm_file_to_image(data->mlx, "img/Exit.xpm",
			&img_w, &img_h);
	if (!data->img->exit)
		handle_error(data, "Error!\nExit file not found\n");
	data->img->coin = mlx_xpm_file_to_image(data->mlx, "img/Coin.xpm",
			&img_w, &img_h);
	if (!data->img->coin)
		handle_error(data, "Error!\nCoin file not found\n");
	data->img->pilar = mlx_xpm_file_to_image(data->mlx, "img/Pilar.xpm",
			&img_w, &img_h);
	if (!data->img->pilar)
		handle_error(data, "Error!\nPilar file not found\n");
}

static void	ft_check_img(t_data *data)
{
	if (!data->img->player_left || !data->img->player_front
		|| !data->img->player_right || !data->img->player_back
		|| !data->img->p_back_exit || !data->img->p_left_exit
		|| !data->img->p_right_exit || !data->img->p_front_exit)
		handle_error(data, "Error!\nPlayer file not found\n");
}

static void	ft_set_player(t_data *data)
{
	int	img_w;
	int	img_h;

	img_w = 50;
	img_h = 50;
	data->img->player_back = mlx_xpm_file_to_image(data->mlx,
			"img/PBack.xpm", &img_w, &img_h);
	data->img->player_left = mlx_xpm_file_to_image(data->mlx,
			"img/PLeft.xpm", &img_w, &img_h);
	data->img->player_right = mlx_xpm_file_to_image(data->mlx,
			"img/PRight.xpm", &img_w, &img_h);
	data->img->player_front = mlx_xpm_file_to_image(data->mlx,
			"img/PFront.xpm", &img_w, &img_h);
	data->img->p_back_exit = mlx_xpm_file_to_image(data->mlx,
			"img/PBackExit.xpm", &img_w, &img_h);
	data->img->p_left_exit = mlx_xpm_file_to_image(data->mlx,
			"img/PLeftExit.xpm", &img_w, &img_h);
	data->img->p_right_exit = mlx_xpm_file_to_image(data->mlx,
			"img/PRightExit.xpm", &img_w, &img_h);
	data->img->p_front_exit = mlx_xpm_file_to_image(data->mlx,
			"img/PFrontExit.xpm", &img_w, &img_h);
	ft_check_img(data);
}

void	ft_init(t_data *data, t_map *map)
{
	t_img	*img;

	data->map = map;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		perror("Error\nmalloc failed\n");
		exit(EXIT_FAILURE);
	}
	data->img = img;
	ft_set_assests(data);
	ft_set_player(data);
	data->counter = 0;
	data->map->coins = 0;
	data->collected = 0;
}
