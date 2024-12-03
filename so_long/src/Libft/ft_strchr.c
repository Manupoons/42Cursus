/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:31:35 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/03 11:50:27 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	x;
	char			aux;

	x = 0;
	aux = (char) c;
	while (s[x])
	{
		if (s[x] == aux)
			return ((char *) &s[x]);
		x++;
	}
	if (s[x] == aux)
		return ((char *) &s[x]);
	return (NULL);
}
