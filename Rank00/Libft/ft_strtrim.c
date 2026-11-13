/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:22:52 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/23 10:44:07 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	x;
	size_t	y;

	str = 0;
	if (s1 && set)
	{
		x = 0;
		y = ft_strlen(s1);
		while (s1[x] && ft_strchr(set, s1[x]))
			x++;
		while (s1[y - 1] && ft_strchr(set, s1[y - 1]) && x < y)
			y--;
		str = (char *)malloc(sizeof(char) * (y - x + 1));
		if (!str)
			return (NULL);
		else if (str)
			ft_strlcpy(str, &s1[x], y - x + 1);
	}
	return (str);
}
