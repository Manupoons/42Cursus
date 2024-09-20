/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:31:35 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/18 12:31:36 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		x;
	char	*dst;
	char	aux;

	x = 0;
	dst = (char *)s;
	aux = c;
	while (dst[x] != aux)
	{
		if (dst[x] == '\0')
			return (NULL);
		x++;
	}
	return ((char *)dst + x);
}
/*
int	main(void)
{
	char str[] = "hola que tal";
	int c = 97;

	printf("%s", ft_strchr(str, c));
}
*/
