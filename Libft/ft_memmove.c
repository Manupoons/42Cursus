/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:32:53 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/17 13:32:55 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		x;
	char		*aux_dst;
	const char	*aux_src;

	x = 0;
	aux_dst = (char *)dest;
	aux_src = (const char *)src;
	if (*(char *)dest == '\0' || *(char *)src == '\0')
	{
		return (0);
	}
	if (aux_dst > aux_src)
	{
		while (n-- > 0)
		{
			aux_dst[n] = aux_src[n];
		}
	}
	else
	{
		x = 0;
		while (x < n)
		{
			aux_dst[x] = aux_src[x];
			x++;
		}
	}
	return (dest);
}
