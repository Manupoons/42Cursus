/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:44:51 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/20 10:44:52 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		x;
	int		sign;
	char	*aux;
	int		num;

	x = 0;
	sign = 1;
	num = 0;
	aux = (char *)nptr;
	while (aux[x] != '\0' && (aux[x] == ' ' || aux[x] == '\n'
			|| aux[x] == '\r' || aux[x] == '\t'
			|| aux[x] == '\v' || aux[x] == '\f'))
		x++;
	if ((char)aux[x] == '-' || (char)aux[x] == '+')
	{
		if ((char)aux[x] == '-')
			sign *= -1;
		x++;
	}
	while (aux[x] != '\0' && (aux[x] >= '0' && aux[x] <= '9'))
	{
		num = num * 10 + aux[x] - '0';
		x++;
	}
	return (num * sign);
}
