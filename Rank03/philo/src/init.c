/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:09:41 by mamaratr          #+#    #+#             */
/*   Updated: 2025/03/07 10:37:12 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
		return (1);
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten= 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].left_fork = &data->forks[(i + 1) % data->num_philos];
		data->philos[i].right_fork = &data->forks[i];
		if (i % 2 == 0)
		{
			data->philos[i].left_fork = &data->forks[i];
			data->philos[i].right_fork = &data->forks[(i + 1)
					% data->num_philos];
		}
		data->philos[i].data = data;
		i++;
	}
	return (0);
}

static int	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (1);
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			data->num_philos = i;
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&data->threads_mutex, NULL) != 0
		|| pthread_mutex_init(&data->print_mutex, NULL) != 0
		|| pthread_mutex_init(&data->eat_mutex, NULL) != 0)
		return (1);
	return (0);
}

void	init_data(t_data *data, char **argv)
{
	data->forks = NULL;
	data->philos = NULL;
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->end_simulation = false;
	data->threads_ready = false;
	data->philo_ready = 0;
	data->philo_full = 0;
	data->start_time = 0;
	if (argv[5])
		data->meals_count = ft_atoi(argv[5]);
	else
		data->meals_count = -1;
	if (init_mutexes(data) != 0 || init_philos(data) != 0)
		error_exit(data, "Error initializing data");
}