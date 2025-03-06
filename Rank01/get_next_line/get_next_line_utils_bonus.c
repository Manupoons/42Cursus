/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:39:33 by mamaratr          #+#    #+#             */
/*   Updated: 2024/10/21 11:39:34 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	int	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char			*res;
	unsigned int	x;
	unsigned int	y;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[y])
		res[x++] = s1[y++];
	y = 0;
	while (s2[y])
		res[x++] = s2[y++];
	res[x] = '\0';
	return (res);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int	x;
	char			aux;

	x = 0;
	aux = (char) c;
	while (s[x])
	{
		if (s[x] == aux)
			return ((char *) &s[x]);
		x++;
	}
	if (s[x] == aux)
		return ((char *) &s[x]);
	return (NULL);
}
