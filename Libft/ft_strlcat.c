/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:03:38 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/19 17:28:53 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	aux_dst;
	size_t	src_length;
	size_t	dst_length;

	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	aux_dst = dst_length;
	x = 0;
	if (size == 0 || size <= dst_length)
		return (src_length + size);
	while (src[x] && x < size - dst_length - 1)
	{
		dst[aux_dst] = src[x];
		aux_dst++;
		x++;
	}
	dst[aux_dst] = '\0';
	return (dst_length + src_length);
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
