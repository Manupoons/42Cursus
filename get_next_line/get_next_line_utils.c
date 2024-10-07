/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:20:08 by mamaratr          #+#    #+#             */
/*   Updated: 2024/10/07 10:36:58 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

char	*ft_strdup(char *s)
{
	char			*dest;
	unsigned int	x;

	dest = malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	x = 0;
	while (s[x])
	{
		dest[x] = s[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	x;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (malloc(1));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	x = 0;
	while (x < len)
	{
		str[x] = s[start + x];
		x++;
	}
	str[x] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*res;

	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	fill_str(res, s1, s2);
	return (res);
}

void	fill_str(char *res, char *s1, char *s2)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (s1[y])
		res[x++] = s1[y++];
	y = 0;
	while (s2[y])
		res[x++] = s2[y++];
	res[x] = '\0';
}
