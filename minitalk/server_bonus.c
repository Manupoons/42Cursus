/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:51:14 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/27 11:38:43 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_pidclient;

void	reset(unsigned int *base, int *result, int *cont)
{
	if (*cont == 40 && *result != 0)
	{
		write(1, &*result, 1);
		*base = 128;
		*cont = 32;
		*result = 0;
	}
	else if (*cont == 40 && *result == 0)
	{
		*cont = 0;
		*base = 2147483648;
	}
}

void	reset2(int *result, unsigned int *base)
{
	g_pidclient = *result;
	*result = 0;
	*base = 128;
}

void	conv_txt(int bit)
{
	static unsigned int	base = 2147483648;
	static int			result = 0;
	static int			i = 0;

	if (i < 32)
	{
		if (bit == SIGUSR1)
			result += base;
		base /= 2;
	}
	if (i == 31)
		reset2(&result, &base);
	if (i >= 32 && i <= 39)
	{
		if (bit == SIGUSR1)
			result += base;
		base /= 2;
		kill(g_pidclient, SIGUSR1);
	}
	i++;
	if (result == 0 && i == 40)
		reset(&base, &result, &i);
	if (i == 40)
		reset(&base, &result, &i);
}

int	main(void)
{
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, conv_txt);
	signal(SIGUSR2, conv_txt);
	while (1)
		pause();
	return (0);
}
