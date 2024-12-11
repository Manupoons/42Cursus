/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:03:59 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/27 11:44:13 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
				letter -= base;
			}
			else
				kill(pid, SIGUSR2);
			usleep(300);
			base /= 2;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		convert_bin(argv[2], pid);
	}
	return (0);
}
