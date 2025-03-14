/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:34:28 by mamaratr          #+#    #+#             */
/*   Updated: 2025/03/14 14:20:58 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_data *data)
{
	pthread_mutex_destroy(&data->threads_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->eat_mutex);
}

void	free_data(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
	}
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
}

void	full_error(t_data *data, char *msg)
{
	printf("%s\n", msg);
	if (data)
	{
		destroy_mutexes(data);
		free_data(data);
	}
	exit(EXIT_FAILURE);
}

void	error(t_data *data, char *msg)
{
	printf("%s\n", msg);
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
}
