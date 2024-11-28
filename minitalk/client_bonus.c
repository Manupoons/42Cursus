/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:03:59 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/27 11:38:28 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	conv_int_bin(unsigned int c, int pid)
{
	unsigned int	base;
	unsigned int	i;

	i = 0;
	base = 2147483648;
	if (i < 32)
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
	i++;
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
