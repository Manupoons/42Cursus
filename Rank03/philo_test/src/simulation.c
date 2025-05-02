/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:22:04 by mamaratr          #+#    #+#             */
/*   Updated: 2025/05/02 16:47:19 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_test.h"

bool	sim_finished(t_data *data)
{
	return (get_bool(&data->threads_mutex, &data->sim_finished));
}

void	wait_threads(t_data *data)
{
	while (!get_bool(&data->threads_mutex, &data->threads_ready))
		usleep(100);
}

int	end_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_join(data->philos[i].philo_thread, NULL) != 0)
			return (1);
		i++;
	}
	if (data->num_philos > 1)
	{
		if (pthread_join(data->monitor_thread, NULL) != 0)
			return (1);
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	wait_threads(data);
	set_long(&data->eat_mutex, &philo->last_meal_time, data->start_time);
	increase_int(&data->threads_mutex, &data->philo_ready);
	if (data->num_philos == 1)
		return (one_philo(philo, data));
	if (philo->id % 2 == 0)
		sleep_ms(data->eat_time / 2, data);
	while (!sim_finished(data))
	{
		philo_eat(philo, data);
		philo_sleep(philo, data);
		philo_think(philo, data);
	}
	return (NULL);
}

int	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&data->philos[i].philo_thread, NULL,
				philo_routine, &data->philos[i]) != 0)
			return (1);
		i++;
	}
	data->start_time = get_current_time();
	set_bool(&data->threads_mutex, &data->threads_ready, true);
	if (data->num_philos > 1)
	{
		if (pthread_create(&data->monitor_thread, NULL, &monitor_routine,
				data) != 0)
			return (1);
	}
	return (0);
}
