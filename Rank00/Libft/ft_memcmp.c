/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:11:28 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/20 10:11:30 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*dst;
	char	*src;
	size_t	x;

	x = 0;
	dst = (char *)s1;
	src = (char *)s2;
	while (x < n)
	{
		if (dst[x] != src[x])
		{
			return ((unsigned char)dst[x] - (unsigned char)src[x]);
		}
		x++;
	}
	return (0);
}
