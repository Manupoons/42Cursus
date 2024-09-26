/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:20:04 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/25 12:24:28 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*
char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	buffer = BUFFER_SIZE;
	fd = open("a.txt", O_RDONLY);
	read(fd, buffer, BUFFER_SIZE);
	if (fd < 0)
		return (NULL);
	printf("Text:  %s\n", buffer);
}
*/

int main()
{
	char	buffer[42];
	//char	*line;

	int fd = open("a.txt", O_RDONLY);
	read(fd, buffer, BUFFER_SIZE);
	if (fd < 0)
		return (0);
	printf("Text:  %s\n", buffer);
	return (0);
}
