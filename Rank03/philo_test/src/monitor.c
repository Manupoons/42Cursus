/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:36:20 by mamaratr          #+#    #+#             */
/*   Updated: 2025/05/02 16:50:05 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_test.h"

static int	check_death(t_philo *philo)
{
	t_data	*data;
	long	time;

	data = philo->data;
	pthread_mutex_lock(&data->eat_mutex);
	time = get_current_time() - philo->last_meal_time;
	pthread_mutex_unlock(&data->eat_mutex);
	if (time >= data->death_time)
	{
		set_bool(&data->threads_mutex, &data->sim_finished, true);
		print_status(philo, "died");
		return (1);
	}
	return (0);
}

static int	check_full(t_data *data)
{
	if (data->meals_count == -1)
		return (0);
	pthread_mutex_lock(&data->eat_mutex);
	if (data->philo_full == data->num_philos)
	{
		set_bool(&data->threads_mutex, &data->sim_finished, true);
		pthread_mutex_unlock(&data->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->eat_mutex);
	return (0);
}

static bool	threads_ready(pthread_mutex_t *mutex, int *threads, int num_philos)
{
	bool	ready;

	ready = false;
	pthread_mutex_lock(mutex);
	if (*threads == num_philos)
		ready = true;
	pthread_mutex_unlock(mutex);
	return (ready);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!threads_ready(&data->threads_mutex, &data->philo_ready,
			data->num_philos))
		usleep(100);
	while (!sim_finished(data))
	{
		i = 0;
		while (i < data->num_philos)
		{
			if (check_death(&data->philos[i]) || check_full(data))
				return (NULL);
			i++;
		}
		usleep (100);
	}
	return (NULL);
}
