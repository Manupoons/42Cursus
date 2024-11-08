/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:44:20 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/05 19:21:50 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	right_move(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectibles != 0)
			return (0);
		printf("Win");
		exit_point(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectibles++;
		game->counter++;
	}
	return (1);
}

static int	keyboard_ws(t_complete *game, int move)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (move == 13)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (move == 1)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	printf("Steps taken: %i\n", game->counter);
	printf("Collectibles remaining: %i\n", game->collectibles);
	return (1);
}

static int	keyboard_ad(t_complete *game, int move)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (move == 0)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (move == 2)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	printf("Steps taken: %i\n", game->counter);
	printf("Collectibles remaining: %i\n", game->collectibles);
	return (1);
}

int	controls_working(int command, t_complete *game)
{
	int	works;
	
	if (command == 53)
		exit_point(game);
	if (command == 13)
		works = keyboard_ws(game, command);
	if (command == 1)
		works = keyboard_ws(game, command);
	if (command == 0)
		works = keyboard_ad(game, command);
	if (command == 2)
		works = keyboard_ad(game, command);
	if (works)
		adding_graphics(game);
	return (1);
}