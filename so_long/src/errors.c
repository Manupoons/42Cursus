/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:44:16 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/09 15:36:38 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	horizontalwall(t_complete *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while (j < i)
	{
		if (game->map[0][i] == '1' && game->map[game->heightmap - 1][j] == '1')
			return (0);
		j++;
	}
	return (1);
}

static int	verticalwall(t_complete *game)
{
	int	height;
	int	width;

	width = game->widthmap;
	height = 0;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1' && game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

static void	if_walls(t_complete *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || horizontalwalls)
	{
		printf("\nWalls missing in map\n");
		exit_point(game);
	}
}

static void	count_checker(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
			game->map[height][width] != '0' &&
			game->map[height][width] != 'P' &&
			game->map[height][width] != 'E' &&
			game->map[height][width] != 'C' &&
			game->map[height][width] != '\n')
	{
		printf("\nError in pos - %c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
		game->columncount++;
	if (game->map[height][width] == 'P')
		game->playercount++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
}

void	character_valid(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->columncount > 1
			&& game->exitcount == 1))
	{
		printf("\nError\n");
		exit_point(game);
	}
}

void	check_errors(t_complete *game)
{
	if_walls(game);
	character_valid(game);
}