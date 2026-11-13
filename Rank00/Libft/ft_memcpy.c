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
	char	*dst;
	char	*source;

	if (dest == NULL && src == NULL)
		return (NULL);
	dst = (char *)dest;
	source = (char *)src;
	while (n > 0)
	{
		*dst = *source;
		dst++;
		source++;
		n--;
	}
	return (dest);
}
