/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:20:08 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/25 11:47:50 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	size_t	length;

	length = 0;
	while (!s)
		length++;
	return (length);
}

char	*ft_strchr(char *s, int c)
{
	int		x;
	char	aux;

	x = 0;
	aux = c;
	while (s[x] != aux)
	{
		if (s[x] == '\0')
			return (NULL);
		x++;
	}
	return ((char *)s + x);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n)
	{
		*(char *)(s + x) = 0;
		x++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;

	if (size != 0 && nmemb > -1 / size)
		return (NULL);
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (nmemb * size));
	return (mem);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[x])
	{
		res[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		res[x + y] = s2[y];
		y++;
	}
	res[x + y] = '\0';
	return (res);
}

