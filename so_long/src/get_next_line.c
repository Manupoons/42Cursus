/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:20 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/11 13:07:22 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*readbuf(int fd, char *line)
{
	int		r;
	char	*buffer;

	r = 1;
	buffer = malloc(sizeof(char) * (1 + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (r > 0 && !ft_strchr(buffer, '\n'))
	{
		r = read (fd, buffer, 1);
		if (r == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (r > 0)
		{
			buffer[r] = '\0';
			line = ft_strjoin(line, buffer);
		}
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*line2;

	line2 = NULL;
	if (fd < 0)
		return (NULL);
	line = readbuf (fd, line2);
	return (line);
}
