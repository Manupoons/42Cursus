/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:45 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/07 08:37:40 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
				put_tree(data);
			else if (tile == 'C')
			{
				put_pokeball(data);
				data->map->pokeballs++;
			}
			else if (tile == 'E')
				put_exit(data);
			data->map->x++;
		}
		data->map->y++;
	}
}
