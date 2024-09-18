/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:23:21 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/17 13:23:23 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	x;

	x = 0;
	if (*(char *)dest == '\0' || *(char *)src == '\0')
	{
		return (0);
	}
	while (x < n)
	{
		*(char *)(dest + x) = *(char *)(src + x);
		x++;
	}
	return (dest);
}
