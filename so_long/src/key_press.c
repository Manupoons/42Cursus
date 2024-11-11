/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:36 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/11 13:07:38 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

void	move_w(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i - d->width] != '1'
		&& !check_exit(d, d->big_line[i - d->width]))
	{
		d->moves++;
		if (d->big_line[i - d->width] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i - d->width] = 'P';
		if (d->npccontrol == 0)
		{
			d->npcstart = d->npcback;
			d->npccontrol = 1;
		}
		else
		{
			d->npcstart = d->npcbmv;
			d->npccontrol = 0;
		}
	}
	print_map(d);
}

void	move_s(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i + d->width] != '1'
		&& !check_exit(d, d->big_line[i + d->width]))
	{
		d->moves++;
		if (d->big_line[i + d->width] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i + d->width] = 'P';
		if (d->npccontrol == 0)
		{
			d->npcstart = d->npc;
			d->npccontrol = 1;
		}
		else
		{
			d->npcstart = d->npcmv;
			d->npccontrol = 0;
		}
	}
	print_map(d);
}

void	move_a(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i - 1] != '1' && !check_exit(d, d->big_line[i - 1]))
	{
		d->moves++;
		if (d->big_line[i - 1] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i - 1] = 'P';
		if (d->npccontrol == 0)
		{
			d->npcstart = d->npcleft;
			d->npccontrol = 1;
		}
		else
		{
			d->npcstart = d->npclmv;
			d->npccontrol = 0;
		}
	}
	print_map(d);
}

void	move_d(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i + 1] != '1' && !check_exit(d, d->big_line[i + 1]))
	{
		d->moves++;
		if (d->big_line[i + 1] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i + 1] = 'P';
		if (d->npccontrol == 0)
		{
			d->npcstart = d->npcright;
			d->npccontrol = 1;
		}
		else
		{
			d->npcstart = d->npcrmv;
			d->npccontrol = 0;
		}
	}
	print_map(d);
}

int	key_press(int key, t_list *d)
{
	char	*moves_p;

	(void)d;
	if (key == 65307) // Escape key in Linux
	{
		mlx_destroy_window(d->mlx, d->win);
		ft_free(d);
	}
	if (key == 119) // W key
		move_w(d);
	if (key == 97)  // A key
		move_a(d);
	if (key == 115) // S key
		move_s(d);
	if (key == 100) // D key
		move_d(d);
	moves_p = ft_itoa(d->moves);
	write(1, moves_p, ft_strlen(moves_p));
	if (moves_p)
		free(moves_p);
	write(1, "\n", 1);
	return (0);
}
