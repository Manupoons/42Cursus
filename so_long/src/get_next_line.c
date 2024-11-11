/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:20:04 by mamaratr          #+#    #+#             */
/*   Updated: 2024/10/11 10:14:19 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *line)
{
	char	*temp;

	temp = ft_strjoin(buffer, line);
	free(buffer);
	return (temp);
}

char	*set_line(char *buffer)
{
	char	*next_line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (buffer[x] != '\n' && buffer[x] != '\0')
		x++;
	if (!buffer[x])
	{
		free(buffer);
		return (NULL);
	}
	next_line = ft_calloc(1, (ft_strlen(buffer) - x + 1));
	x++;
	while (buffer[x])
		next_line[y++] = buffer[x++];
	free(buffer);
	return (next_line);
}

char	*fill_line(char *buffer)
{
	char	*line;
	int		x;

	x = 0;
	if (!buffer[x])
		return (NULL);
	while (buffer[x] && buffer[x] != '\n')
		x++;
	if (buffer[x] == '\n')
		line = ft_calloc(1, x + 2);
	else if (buffer[x] == '\0')
		line = ft_calloc(1, x + 1);
	x = 0;
	while (buffer[x] && buffer[x] != '\n')
	{
		line[x] = buffer[x];
		x++;
	}
	if (buffer[x] == '\n')
		line[x] = '\n';
	return (line);
}

char	*read_buffer(int fd, char *buffer)
{
	int		bytes;
	char	*line;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, line, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(line), NULL);
		if (bytes == 0)
			break ;
		line[bytes] = '\0';
		buffer = ft_free(buffer, line);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	if (!buffer)
	{
		free (buffer);
		return (NULL);
	}
	line = fill_line(buffer);
	buffer = set_line(buffer);
	return (line);
}
