/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:59:52 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/20 09:59:54 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*aux;

	aux = (unsigned char *)s;
	x = 0;
	while (x < n)
	{
		if ((char)aux[x] == (char)c)
		{
			return ((char *)s + x);
		}
		x++;
	}
	return (0);
}
