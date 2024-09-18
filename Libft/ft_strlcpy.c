/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:17:27 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/17 15:17:29 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	src_length;

	src_length = ft_strlen(src);
	x = 0;
	if (size == 0)
	{
		return (src_length);
	}
	while (x < (size - 1) && src)
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (src_length);
}
/*
int	main(void)
{
	char dst[] = "";
	char src[] = "hola";
	size_t val = 4;

	printf("%s", dst);
	ft_strlcpy(dst, src, val);
	printf("%s", dst);
}
*/
