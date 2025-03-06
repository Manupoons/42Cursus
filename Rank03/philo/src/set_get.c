/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:18:17 by mamaratr          #+#    #+#             */
/*   Updated: 2025/03/06 12:21:18 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool val)
{
	pthread_mutex_lock(mutex);
	*dest = val;
	pthread_mutex_unlock(mutex);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long val)
{
	pthread_mutex_lock(mutex);
	*dest = val;
	pthread_mutex_unlock(mutex);
}

bool	get_bool(pthread_mutex_t *mutex, bool *val)
{
	bool	res;

	pthread_mutex_lock(mutex);
	res = *val;
	pthread_mutex_unlock(mutex);
	return (res);
}

long	get_long(pthread_mutex_t *mutex, long *val)
{
	long	res;

	pthread_mutex_lock(mutex);
	res = *val;
	pthread_mutex_unlock(mutex);
	return (res);
}

void	increase_int(pthread_mutex_t *mutex, int *val)
{
	pthread_mutex_lock(mutex);
	(*val)++;
	pthread_mutex_unlock(mutex);
}