/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:10:24 by mamaratr          #+#    #+#             */
/*   Updated: 2025/03/14 14:19:30 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*one_philo(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	sleep_ms(data->death_time, data);
	pthread_mutex_unlock(philo->left_fork);
	print_status(philo, "died");
	return (NULL);
}

static void	philo_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork");
	set_long(&data->eat_mutex, &philo->last_meal_time, get_current_time());
	print_status(philo, "is eating");
	if (data->meals_count != -1)
	{
		philo->meals_eaten++;
		if (philo->meals_eaten == data->meals_count)
			increase_int(&data->eat_mutex, &data->philo_full);
	}
	sleep_ms(data->eat_time, data);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	philo_sleep(t_philo *philo, t_data *data)
{
	if (!sim_finished(data))
	{
		print_status(philo, "is sleeping");
		sleep_ms(data->sleep_time, data);
	}
}

static void	philo_think(t_philo *philo, t_data *data)
{
	int	t_eat;
	int	t_sleep;
	int	t_think;

	if (data->num_philos % 2 == 0)
		print_status(philo, "is thinking");
	else
	{
		t_eat = data->eat_time;
		t_sleep = data->sleep_time;
		t_think = t_eat * 2 + t_sleep;
		print_status(philo, "is thinking");
		sleep_ms(t_think * 0.42, data);
	}
}

void	*philo_routine(void	*arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	wait_threads(data);
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
