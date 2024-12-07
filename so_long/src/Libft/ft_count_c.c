/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:35:01 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/07 19:24:52 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_c(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (-1);
	while (s && s[i])
	{
		if (s[i++] == c)
			count++;
	}
	return (count);
}
