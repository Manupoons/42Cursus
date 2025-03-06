/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:36 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/11 12:41:33 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

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
