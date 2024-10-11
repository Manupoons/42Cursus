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

static char	*set_line(char *line)
{
	char	*aux;
	ssize_t	x;

	x = 0;
	while (line[x] != '\n' && line[x] != '\0')
		x++;
	if (line[x] == 0)
		return (0);
	aux = ft_substr(line, x + 1, ft_strlen(line) - x);
	if (*aux == 0)
	{
		free(aux);
		aux = NULL;
	}
	line[x + 1] = 0;
	return (aux);
}

static char	*fill_line(int fd, char *aux, char *buffer)
{
	ssize_t	bytes;
	char	*temp;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(aux);
			return (0);
		}
		else if (bytes == 0)
			break ;
		buffer[bytes] = 0;
		if (!aux)
			aux = ft_strdup("");
		temp = aux;
		aux = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*aux;
	char		*buffer;
	char		*line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(aux);
		free(buffer);
		aux = NULL;
		buffer = NULL;
		return (0);
	}
	if (!buffer)
		return (NULL);
	line = fill_line(fd, aux, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	aux = set_line(line);
	return (line);
}
