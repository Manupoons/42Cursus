/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:45:51 by mamaratr          #+#    #+#             */
/*   Updated: 2025/03/07 10:55:29 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_test.h"

static void	validate_input(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		error_exit(NULL, HELP_MSG);
	i = 1;
	while (i < argc)
	{
		j = ft_atoi(argv[i]);
		if (j == 0)
			error_exit(NULL, "Invalid argument");
		i++;
	}
}

void	destroy_mutexes(t_data *data)
{
	pthread_mutex_destroy(&data->threads_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->eat_mutex);
}

void	clean_up(t_data *data)
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

int	main(int argc, char **argv)
{
	t_data	data;

	validate_input(argc, argv);
	init_data(&data, argv);
	if (start_simulation(&data) != 0)
		error_full(&data, "Error creating threads");
	if (finish_simulation(&data) != 0)
		error_full(&data, "Error joining threads");
	destroy_mutexes(&data);
	clean_up(&data);
	return (EXIT_SUCCESS);
}
