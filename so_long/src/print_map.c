/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:45 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/11 13:07:48 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

void	calc_xy(char r, int i, t_list *d)
{
	int	x_;
	int	y_;

	y_ = (i / d->width) * 50;
	x_ = (i % d->width) * 50;
	if (d->errors == 0)
	{
		if (r == 'C')
			mlx_put_image_to_window (d->mlx, d->win, d->poke, x_, y_);
		if (r == 'E')
			mlx_put_image_to_window (d->mlx, d->win, d->imgexit, x_, y_);
		if (r == '1')
			mlx_put_image_to_window (d->mlx, d->win, d->bush, x_, y_);
		if (r == '0')
			mlx_put_image_to_window (d->mlx, d->win, d->fond, x_, y_);
		if (r == 'P')
			mlx_put_image_to_window (d->mlx, d->win, d->npcstart, x_, y_);
	}
}

void	print_map(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i])
	{
		if (d->big_line[i] == '\n')
			i++;
		if (d->big_line[i] != 'C' && d->big_line[i] != 'E'
			&& d->big_line[i] != '1'
			&& d->big_line[i] != '0' && d->big_line[i] != 'P')
			exit(0);
		if (d->big_line[i] == 'C')
			calc_xy('C', i, d);
		if (d->big_line[i] == 'E')
			calc_xy('E', i, d);
		if (d->big_line[i] == '1')
			calc_xy('1', i, d);
		if (d->big_line[i] == '0')
			calc_xy('0', i, d);
		if (d->big_line[i] == 'P')
			calc_xy('P', i, d);
		i++;
	}
}
