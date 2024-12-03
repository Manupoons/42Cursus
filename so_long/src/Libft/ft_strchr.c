/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:31:35 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/03 15:07:27 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		x;
	char	aux;

	if (!s)
		return (NULL);
	x = 0;
	aux = c;
	while (s && s[x] && s[x] != aux)
		x++;
	if (s[x] == aux)
		return ((char *)(s + x));
	else
		return (NULL);
}
