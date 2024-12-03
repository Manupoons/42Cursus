/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:42:29 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/03 11:17:54 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char	*str)
{
	int	x;

	x = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
	return (x);
}

int	ft_convert(va_list v1, const char s)
{
	int	val;

	val = 0;
	if (s == 'c')
		val += ft_putchar(va_arg(v1, int));
	else if (s == 's')
		val += ft_putstr(va_arg(v1, char *));
	else if (s == 'd' || s == 'i')
		val += ft_putnbr((va_arg(v1, int)));
	else if (s == '%')
		val += ft_putchar('%');
	return (val);
}

int	ft_printf(char const *s, ...)
{
	va_list	v1;
	int		val;
	int		x;

	x = 0;
	val = 0;
	va_start(v1, s);
	while (s[x])
	{
		if (s[x] == '%')
		{
			val += ft_convert(v1, s[x + 1]);
			x++;
		}
		else
			val += ft_putchar(s[x]);
		x++;
	}
	va_end(v1);
	return (val);
}
