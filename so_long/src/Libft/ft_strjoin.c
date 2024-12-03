/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:59:10 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/03 11:44:27 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, const char *s2)
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
