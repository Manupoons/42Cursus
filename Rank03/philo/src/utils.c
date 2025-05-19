/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:34:09 by mamaratr          #+#    #+#             */
/*   Updated: 2025/05/16 13:04:42 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	sleep_ms(long time, t_data *data)
{
	long	start;

	start = get_current_time();
	while (!sim_finished(data) && (get_current_time() - start) < time)
		usleep(100);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		else if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!sim_finished(philo->data) || ft_strcmp(status, "died") == 0)
		printf("%ld %d %s\n", get_current_time() - philo->data->start_time,
			philo->id, status);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	ft_atoi(const char *str)
{
	long	res;

	res = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + *str - '0';
		if (res > INT_MAX)
			error(NULL, "Error: Integer overflow");
		str++;
	}
	return ((int)res);
}
