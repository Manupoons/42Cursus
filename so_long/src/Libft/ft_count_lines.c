/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:34:59 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/03 11:29:43 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	exit_error(void)
{
	write(1, "Error\nWrong map dimensionsn", 27);
	exit(EXIT_FAILURE);
}

int	ft_count_lines(int fd, int x, int img_w)
{
	char	*line;
	int		linecount;

	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if ((int)ft_strlen(line) < x / img_w
				|| (ft_strlen(line) == 1 && *line != '\n'))
		{
			free(line);
			exit_error();
		}
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}