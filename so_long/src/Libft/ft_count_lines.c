/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:34:59 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/09 09:50:47 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_lines(int fd, int expected_width, int img_w)
{
	char	*line;
	int		linecount;
	int		line_length;

	line = get_next_line(fd);
	linecount = 0;
	while (line != NULL)
	{
		line_length = ft_strlen(line);
		if (line[line_length - 1] == '\n')
			line_length--;
		if (line_length < expected_width / img_w)
		{
			free(line);
			write(2, "Error\nWrong map dimensions\n", 27);
			exit(EXIT_FAILURE);
		}
		free(line);
		linecount++;
		line = get_next_line(fd);
	}
	return (linecount);
}
