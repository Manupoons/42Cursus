/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:36:20 by mamaratr          #+#    #+#             */
/*   Updated: 2025/03/06 15:53:53 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_test.h"

static int	check_death(t_philo *philo)
{
	t_data	*data;
	long	time;

	data = philo->data;
	pthread_mutex_lock(&data->eat_mutex);
	time = current_time() - philo->last_meal_time;
	pthread_mutex_unlock(&data->eat_mutex);
	if (time >= data->time_to_die)
	{
		set_bool(&data->threads_mutex, &data->end_simulation, true);
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
		set_bool(&data->threads_mutex, &data->end_simulation, true);
		pthread_mutex_unlock(&data->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->eat_mutex);
	return (0);
}

bool	threads_ready(pthread_mutex_t *mutex, int *threads, int philo_num)
{
	bool	res;

	res = false;
	pthread_mutex_lock(mutex);
	if (*threads == philo_num)
		res = true;
	pthread_mutex_unlock(mutex);
	return (res);
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
		usleep(100);
	}
	return (NULL);
}
