/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:07:20 by mamaratr          #+#    #+#             */
/*   Updated: 2025/03/14 14:29:50 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
