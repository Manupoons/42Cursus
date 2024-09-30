/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:48:09 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/30 10:48:11 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_numsize(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	x;
	long	num;

	x = 0;
	num = (long)n;
	len = ft_numsize(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[x] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[(len - 1) - x++] = (num % 10) + '0';
		num /= 10;
	}
	str[len] = '\0';
	return (str);
}

int	ft_putnbr(int num)
{
	int		len;
	char	*n;

	n = ft_itoa(num);
	len = ft_putstr(n);
	free(n);
	return (len);
}
