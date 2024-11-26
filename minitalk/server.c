/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:51:14 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/26 11:43:31 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_putchar(int c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
		num = num % 10;
	}
	if (num <= 9)
		ft_putchar (('0' + num));
}

void	conv_txt(char *s)
{
	int	base;
	int	result;
	int	i;

	base = 128;
	result = 0;
	i = 0;
	while (i < 8)
	{
		if (s[i] == '1')
			result += base;
		base /= 2;
		i++;
	}
	write(1, &result, 1);
}

void	handle_bin(int sig)
{
	static int	i;
	static char	c[8];

	if (sig == SIGUSR1)
		c[i] = '1';
	else if (sig == SIGUSR2)
		c[i] = '0';
	i++;
	if (i == 8)
	{
		i = 0;
		if (ft_strcmp(c, "00000000") == 0)
		{
			write(1, "\n", 1);
			return;
		}
		conv_txt(c);
		for (int j = 0; j < 8; j++)
			c[j] = '\0';
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, handle_bin);
	signal(SIGUSR2, handle_bin);
	while (1)
		sleep(1);
	return (0);
}
