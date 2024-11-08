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

void	convert_bin(char *s, int pid)
{
	int		i;
	int		base;
	char	letter;

	i = 0;
	while (s[i])
	{
		base = 128;
		letter = s[i];
		while (base > 0)
		{
			if (letter >= base)
			{
				kill(pid, SIGUSR1);
				letter = letter - base;
			}
			else
				kill(pid, SIGUSR2);
			base = base / 2;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (-1);
	pid = ft_atoi(argv[1]);
	convert_bin(argv[2], pid);
	return (0);
}
