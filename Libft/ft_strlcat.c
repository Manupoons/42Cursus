/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:03:38 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/17 16:03:40 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	src_length;
	size_t	dst_length;

	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	x = 0;
	if (size == 0)
	{
		return (src_length);
	}
	while (x < (size - 1) && src)
	{
		dst[dst_length + x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (src_length + dst_length);
}
/*
int	main(void)
{
	char dst[] = "adios";
	char src[] = "hola";
	size_t val = 9;

	printf("%s\n", dst);
	ft_strlcat(dst, src, val);
	printf("%s", dst);
}
*/
