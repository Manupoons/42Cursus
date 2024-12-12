/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:04:59 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/10 14:55:01 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	find_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
			}
			x++;
		}
		y++;
	}
}

void	free_double_p(char ***str)
{
	int	i;

	i = 0;
	if (*str)
	{
		while ((*str)[i])
		{
			free((*str)[i]);
			i++;
		}
		free(*str);
		*str = NULL;
	}
}

void	free_double_pointer(t_data *data)
{
	int	i;

	if (!data->map || !data->map->map)
		return ;
	i = 0;
	while (data->map->map[i])
		i++;
	while (i >= 0)
	{
		free(data->map->map[i]);
		data->map->map[i] = NULL;
		i--;
	}
	free(data->map->map);
	data->map->map = NULL;
	free(data->img);
	data->img = NULL;
}

void	calloc_fail(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	handle_error(t_data *data, char *str)
{
	free_double_pointer(data);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
