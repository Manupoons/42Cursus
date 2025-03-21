/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:03:59 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/15 17:50:20 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int	g_sig_recieved = 0;

static void	handle_signal(int sig)
{
	g_sig_recieved = sig;
}

void	send_char(unsigned char c, int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_sig_recieved = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit--;
		while (g_sig_recieved != SIGUSR1)
			usleep(100);
	}
}

void	send_msg(char *msg, int pid)
{
	while (*msg)
	{
		send_char((unsigned char)*msg, pid);
		msg++;
	}
	send_char('\0', pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(2, "Ejemplo de uso: (./client pid mensaje)", 38);
		return (1);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		send_msg(argv[2], pid);
	}
	return (0);
}
