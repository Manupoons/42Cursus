/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:52:28 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/18 12:52:30 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_length;

	s_length = ft_strlen(s);
	while (s[s_length] > 0)
	{
		if (s[s_length] == c)
		{
			return ((char *)s);
		}
		s_length--;
		s--;
	}
	return (0);
}
/*
int	main(void)
{
	char str[] = "hola que tal";
	int c = 97;

	printf("%s", ft_strrchr(str, c));
}
*/
