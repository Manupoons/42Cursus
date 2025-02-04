/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:10:12 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/04 20:59:34 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_borders(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->size_y / IMG_H))
	{
		if ((int)ft_strlen(data->map->map[y]) != data->size_x / IMG_W)
			handle_error(data, "Error!\nMap has to be rectangular\n");
		x = 0;
		while (x < (data->size_x / IMG_W))
		{
			if (data->map->map[y][x] != '0' && data->map->map[y][x] != '1' &&
				data->map->map[y][x] != 'C' && data->map->map[y][x] != 'P' &&
				data->map->map[y][x] != 'E')
				handle_error(data, "Error\nMap must be: 0,1,C,P,E only\n");
			else if (((y == 0) || (x == 0)) && data->map->map[y][x] != '1')
				handle_error(data, "Error\nWalls missing\n");
			else if ((y == (data->size_y / IMG_H - 1)
					|| x == (data->size_x / IMG_W - 1))
				&& data->map->map[y][x] != '1')
				handle_error(data, "Error\nWalls missing\n");
			x++;
		}
		y++;
	}
}

static void	check_content(t_data *data)
{
	int	y;
	int	exit;
	int	player;

	check_borders(data);
	exit = 0;
	player = 0;
	y = 0;
	while (data->map->map && data->map->map[y])
	{
		exit += ft_count_c(data->map->map[y], 'E');
		player += ft_count_c(data->map->map[y], 'P');
		y++;
	}
	if (player != 1)
		handle_error(data, "Error!\nMust have 1 player only\n");
	if (exit != 1)
		handle_error(data, "Error!\nMust have 1 exit only\n");
}

void	validate_map(t_data *data, char **argv, int argc)
{
	int		fd;
	int		i;
	int		bytes;
	char	buffer[2];

	if (argc == 2)
	{
		i = 0;
		bytes = 1;
		buffer[1] = '\0';
		fd = open(argv[1], O_RDONLY);
		while (bytes == 1)
		{
			bytes = read(fd, buffer, 1);
			if (bytes != 1)
				break ;
			if (buffer[0] != '\n' && buffer[0] != '\0')
				data->map->map[i] = ft_strjoin(data->map->map[i], buffer);
			else
				i++;
		}
		if (data->size_x / IMG_H == i)
			handle_error(data, "Error!\nWrong map dimensions\n");
		check_content(data);
	}
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
				put_pilar(data);
			else if (tile == 'C')
			{
				put_coin(data);
				data->map->coins++;
			}
			else if (tile == 'E')
				put_exit(data);
			data->map->x++;
		}
		data->map->y++;
	}
}
