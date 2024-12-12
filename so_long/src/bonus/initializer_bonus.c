/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:36:27 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/10 14:45:01 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
#include "../mlx/mlx.h"

static void	ft_set_assests(t_data *data)
{
	int	img_w;
	int	img_h;

	img_w = 50;
	img_h = 50;
	data->img->background = mlx_xpm_file_to_image(data->mlx, "img/ground.xpm",
			&img_w, &img_h);
	if (!data->img->background)
		handle_error(data, "Error!\nGround file not found\n");
	data->img->exit = mlx_xpm_file_to_image(data->mlx, "img/exit.xpm",
			&img_w, &img_h);
	if (!data->img->exit)
		handle_error(data, "Error!\nExit file not found\n");
	data->img->pokeball = mlx_xpm_file_to_image(data->mlx, "img/pokeball.xpm",
			&img_w, &img_h);
	if (!data->img->pokeball)
		handle_error(data, "Error!\nPokeball file not found\n");
	data->img->tree = mlx_xpm_file_to_image(data->mlx, "img/tree.xpm",
			&img_w, &img_h);
	if (!data->img->tree)
		handle_error(data, "Error!\nTree file not found\n");
}

static void	ft_set_characters(t_data *data)
{
	int	img_w;
	int	img_h;

	img_w = 50;
	img_h = 50;
	data->img->enemy_1 = mlx_xpm_file_to_image(data->mlx, "img/enemy_1.xpm",
			&img_w, &img_h);
	data->img->enemy_2 = mlx_xpm_file_to_image(data->mlx, "img/enemy_2.xpm",
			&img_w, &img_h);
	data->img->player_up = mlx_xpm_file_to_image(data->mlx, "img/npcup.xpm",
			&img_w, &img_h);
	data->img->player_left = mlx_xpm_file_to_image(data->mlx, "img/npclft.xpm",
			&img_w, &img_h);
	data->img->player_right = mlx_xpm_file_to_image(data->mlx, "img/npcr.xpm",
			&img_w, &img_h);
	data->img->player_down = mlx_xpm_file_to_image(data->mlx, "img/npcdown.xpm",
			&img_w, &img_h);
	if (!data->img->player_left || !data->img->player_down
		|| !data->img->player_right || !data->img->player_up)
		handle_error(data, "Error!\nPlayer file not found\n");
	if (!data->img->enemy_1 || !data->img->enemy_2)
		handle_error(data, "Error!\nEnemy file not found\n");
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
	ft_set_characters(data);
	data->counter = 0;
	data->map->pokeballs = 0;
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
