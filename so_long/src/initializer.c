/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:36:27 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/02 13:51:09 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_set_img(t_data *data)
{
	char	*path;
	int		img_w;
	int		img_h;

	path = "../img/npcup.xpm";
	data->img->player_up = mlx_xpm_file_to_image(data->mlx, path,
				&img_w, &img_h);
	path = "../img/npcleft.xpm";
	data->img->player_left = mlx_xpm_file_to_image(data->mlx, path,
				&img_w, &img_h);
	path = "../img/npcright.xpm";
	data->img->player_right = mlx_xpm_file_to_image(data->mlx, path,
				&img_w, &img_h);
	path = "../img/npcdown.xpm";
	data->img->player_down = mlx_xpm_file_to_image(data->mlx, path,
				&img_w, &img_h);
	if (!data->img->player_left || !data->img->player_down ||
			!data->img->player_right || !data->img->player_up)
		handle_error(data, "Error!\nPlayer file not found", 1);
	path = "../img/background.xpm";
	data->img->background = mlx_xpm_file_to_image(data->mlx, path,
				&img_w, &img_h);
	if (!data->img->background)
		handle_error(data, "Error!\nBackground file not found", 1);
}

void	ft_init(t_data *data, t_map *map)
{
	char	*path;
	int		img_w;
	int		img_h;
	t_img	*img;

	data->map = map;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		perror("Error\nmalloc failed");
		exit(EXIT_FAILURE);
	}
	data->img = img;
	ft_set_img(data);
	data->counter = 0;
	data->collected = 0;
}