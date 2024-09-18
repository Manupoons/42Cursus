/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:27:19 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/17 12:27:20 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	x;
	char	*str;

	x = 0;
	str = (char *)s;
	while (x < n)
	{
		str[x] = c;
		x++;
	}
	return (str);
}

/*
int main(void)
{
	char s[] = "Hola que tal";
	int c = 98;
	size_t n = 5;
	printf("%s", (char *)ft_memset(s, c, n));
}
*/
