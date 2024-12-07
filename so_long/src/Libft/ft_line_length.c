/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:34:56 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/07 19:25:09 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_line_length(int fd)
{
	char	buffer[1];
	int		len;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	len = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			len++;
		else
			break ;
	}
	return (len);
}
