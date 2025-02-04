/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:36:27 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/04 20:56:56 by mamaratr         ###   ########.fr       */
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

static void	ft_set_player(t_data *data)
{
	int	img_w;
	int	img_h;

	img_w = 50;
	img_h = 50;
	data->img->player_up = mlx_xpm_file_to_image(data->mlx, "img/PBack.xpm",
			&img_w, &img_h);
	data->img->player_left = mlx_xpm_file_to_image(data->mlx, "img/PLeft.xpm",
			&img_w, &img_h);
	data->img->player_right = mlx_xpm_file_to_image(data->mlx, "img/PRight.xpm",
			&img_w, &img_h);
	data->img->player_down = mlx_xpm_file_to_image(data->mlx, "img/PFront.xpm",
			&img_w, &img_h);
	if (!data->img->player_left || !data->img->player_down
		|| !data->img->player_right || !data->img->player_up)
		handle_error(data, "Error!\nPlayer file not found\n");
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

void	window_size(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nInvalid map_path\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		perror("Error\nMap has to be .ber\n");
		exit(EXIT_FAILURE);
	}
	data->size_x = (ft_line_length(fd) * IMG_W);
	data->size_y = (ft_count_lines(fd, data->size_x, IMG_W) * IMG_H);
	close(fd);
}
