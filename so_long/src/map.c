/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:43:59 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/05 15:09:19 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	width_of_map(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (str[len - 1] == '\n')
		len--;
	return (len);
}

static int	add_line(t_complete *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temp = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	temp[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	map_reading(t_complete *game, char **argv)
{
	char	*map;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		map = get_next_line(game->fd);
		if (!add_line(game, map))
			break ;
	}
	close (game->fd);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}