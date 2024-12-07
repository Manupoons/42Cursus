/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:06:16 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/07 19:55:25 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	valid_exit(t_data *data, int x, int y, char **visited)
{
	int	up;
	int	down;
	int	right;
	int	left;

	if (y < 0 || y >= data->size_y || x < 0 || x >= data->size_x
		|| data->map->map[y][x] == '1' || visited[y][x] == '1')
		return (0);
	if (data->map->map[y][x] == 'E')
		return (1);
	visited[y][x] = '1';
	up = valid_exit(data, x, y - 1, visited);
	down = valid_exit(data, x, y + 1, visited);
	right = valid_exit(data, x + 1, y, visited);
	left = valid_exit(data, x - 1, y, visited);
	if (up || down || left || right)
		return (1);
	else
		return (0);
}

int	valid_collectibles(t_data *data, int x, int y, char **visited)
{
	int	up;
	int	down;
	int	right;
	int	left;

	if (y < 0 || y >= data->size_y || x < 0 || x >= data->size_x
		|| data->map->map[y][x] == '1' || visited[y][x] == '1'
		|| visited[y][x] == 'E')
		return (0);
	if (data->map->map[y][x] == 'P')
		return (1);
	visited[y][x] = '1';
	up = valid_collectibles(data, x, y - 1, visited);
	down = valid_collectibles(data, x, y + 1, visited);
	right = valid_collectibles(data, x + 1, y, visited);
	left = valid_collectibles(data, x - 1, y, visited);
	if (up || down || left || right)
		return (1);
	else
		return (0);
}

static void	fill_visited(char ***visited, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map->map[y])
	{
		(*visited)[y] = malloc(sizeof(char) * (data->size_x + 1));
		if (!(*visited)[y])
		{
			while (--y >= 0)
				free((*visited)[y]);
			free(*visited);
			handle_error(data, "Error!\n allocation failure\n");
		}
		x = 0;
		while (data->map->map[y][x])
		{
			(*visited)[y][x] = data->map->map[y][x];
			x++;
		}
		(*visited)[y][x] = '\0';
		y++;
	}
}

void	check_collectibles_path(t_data *data, int x, int y)
{
	char	**visited;

	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'C')
			{
				visited = malloc(sizeof(char *) * (data->size_y + 1));
				if (!visited)
					handle_error(data, "Error!\n allocation failure.\n");
				visited[data->size_y] = 0;
				fill_visited(&visited, data);
				if (!valid_collectibles(data, x, y, visited))
					handle_error(data, "Error!\nNo path for collectibles\n");
				free_double_p(&visited);
			}
			x++;
		}
		y++;
	}
}

void	check_path(t_data *data)
{
	char	**visited;
	int		x;
	int		y;

	x = 0;
	y = 0;
	find_player(data);
	visited = malloc(sizeof(char *) * (data->size_y + 1));
	if (!visited)
		handle_error(data, "Error!\n allocation failure.\n");
	visited[data->size_y] = NULL;
	fill_visited(&visited, data);
	if (!valid_exit(data, data->p_x, data->p_y, visited))
	{
		free_double_p(&visited);
		handle_error(data, "Error!\n No valid path.\n");
	}
	free_double_p(&visited);
	check_collectibles_path(data, x, y);
}
