/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:03:59 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/26 11:41:16 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	conv_int_bin(unsigned int c, int pid)
{
	unsigned int	base;
	unsigned int	cont;

	cont = 0;
	base = 2147483648;
	if (cont < 32)
	{
		while (base > 0)
		{
			if (c >= base)
			{
				kill(pid, SIGUSR1);
				c -= base;
			}
			else
				kill(pid, SIGUSR2);
			base /= 2;
			usleep(300);
		}
	}
	usleep(500);
	cont++;
}

void	convert_bin(unsigned char c, int pid)
{
	int	base;

	base = 128;
	while (base > 0)
	{
		if (c >= base)
		{
			kill(pid, SIGUSR1);
			c -= base;
		}
		else
			kill(pid, SIGUSR2);
		base /= 2;
		usleep(300);
	}
	usleep(500);
}

void	confirm(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Received bit\n", 13);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		return (-1);
	signal(SIGUSR1, confirm);
	pid = ft_atoi(argv[1]);
	conv_int_bin(getpid(), pid);
	while (argv[2][i])
	{
		convert_bin(argv[2][i], pid);
		i++;
	}
	convert_bin('\0', pid);
	return (0);
}
