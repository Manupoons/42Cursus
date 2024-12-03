/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:44:51 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/03 14:58:36 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		x;
	int		sign;
	int		num;

	x = 0;
	sign = 1;
	num = 0;
	while (str[x] == ' ' && (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			sign = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		num = num * 10 + str[x] - '0';
		x++;
	}
	return (num * sign);
}
