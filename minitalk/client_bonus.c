/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:03:59 by mamaratr          #+#    #+#             */
/*   Updated: 2024/10/31 11:24:18 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	conv_int_bin(unsigned int c, int pid)
{
		unsigned int base;
		unsigned int cont;

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
				base /=2;
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
		base = base / 2;
		usleep(300);
	}
	usleep(500);
}

void	confirm(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Received bits\n", 13);
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
	conv_int_bin(getgid(), pid);
	while (argv[2][i++])
		convert_bin(argv[2][i], pid);
	convert_bin('\0', pid);
	return (0);
}
