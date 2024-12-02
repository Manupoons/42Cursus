/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:25:23 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/20 10:25:24 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*aux_big;
	char	*aux_lit;
	size_t	x;
	size_t	length;

	if (*little == '\0')
		return ((char *)big);
	x = 0;
	aux_big = (char *)big;
	aux_lit = (char *)little;
	length = ft_strlen(aux_lit);
	while (aux_big[x] && (x + length) <= len)
	{
		if (ft_strncmp((aux_big + x), aux_lit, length) == 0)
			return (aux_big + x);
		x++;
	}
	return (NULL);
}
