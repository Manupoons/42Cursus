/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:10:24 by mamaratr          #+#    #+#             */
/*   Updated: 2025/04/30 12:48:21 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	sleep_ms(data->death_time, data);
	pthread_mutex_unlock(philo->left_fork);
	print_status(philo, "died");
	return (NULL);
}

void	philo_eat(t_philo *philo, t_data *data)
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

void	philo_sleep(t_philo *philo, t_data *data)
{
	if (!sim_finished(data))
	{
		print_status(philo, "is sleeping");
		sleep_ms(data->sleep_time, data);
	}
}

void	philo_think(t_philo *philo, t_data *data)
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
