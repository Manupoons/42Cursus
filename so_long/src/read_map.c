/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:58 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/11 13:07:59 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_start_line(t_list *d)
{
	int	i;

	i = d->width - 2;
	while (i < ft_strlen(d->big_line))
	{
		if (d->big_line[i] == '1')
			i = i + d->width;
		else
			ft_error(d, 2);
	}
	i = d->width;
	while (i < ft_strlen(d->big_line))
	{
		if (d->big_line[i] == '1')
			i = i + d->width;
		else
			ft_error(d, 1);
	}
}

void	check_fst_line(t_list *d)
{
	int	i;
	int	last;

	i = 0;
	last = ft_strlen(d->big_line) - d->width;
	while (i != d->width)
	{
		if (d->big_line[i] == '1' || d->big_line[i] == '\n')
			i++;
		else
			ft_error(d, 3);
	}
	while (last != ft_strlen(d->big_line))
	{
		if (d->big_line[last] == '1' || d->big_line[last] == '\n')
			last++;
		else
			ft_error(d, 4);
	}
	check_start_line(d);
}

void	checkline(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i])
	{
		if (d->big_line[i] != 'C' && d->big_line[i] != 'E'
			&& d->big_line[i] != '1'
			&& d->big_line[i] != '0' && d->big_line[i] != 'P'
			&& d->big_line[i] != '\n')
			ft_error(d, 8);
		if (d->big_line[i] == 'C')
			d->consum++;
		if (d->big_line[i] == 'E')
			d->ex++;
		if (d->big_line[i] == '1')
			d->wall++;
		if (d->big_line[i] == '0')
			d->back++;
		if (d->big_line[i] == 'P')
			d->player++;
		i++;
	}
	if (d->consum < 1 || d->ex < 1 || d->wall < 1
		|| d->player != 1)
		ft_error(d, 5);
}

void	check_line_break(char *line, t_list *d)
{
	int	i;

	i = 0;
	d->linecontrol = 1;
	while (line[i])
	{
		if (line[i] == '\n')
			d->linecontrol = 0;
		i++;
	}
}

void	read_map(char *map, t_list *d)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_free(d);
	d->linecontrol = 2;
	while (d->linecontrol != 1)
	{
		d->height++;
		line = get_next_line(fd);
		if (!line)
			ft_error(d, 9);
		if (d->linecontrol == 2)
			d->width = ft_strlen(line);
		check_line_break(line, d);
		if (ft_strlen(line) + d->linecontrol != d->width)
			ft_error(d, 7);
		d->big_line = ft_strjoin(d->big_line, line);
		if (line)
			free(line);
	}
	close(fd);
	check_fst_line(d);
	checkline(d);
}
