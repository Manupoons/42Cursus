/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:18:46 by mamaratr          #+#    #+#             */
/*   Updated: 2025/03/07 10:55:38 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TEST_H
# define PHILO_TEST_H

#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define HELP_MSG "Usage: ./philo <number_of_philosophers> <time_to_die> \
<time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]"

struct s_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_count;
	int				philo_ready;
	int				philo_full;
	long			start_time;
	bool			threads_ready;
	bool			end_simulation;
	pthread_t		monitor_thread;
	pthread_mutex_t	threads_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_mutex;
	t_philo			*philos;
}	t_data;

// simuation

int		start_simulation(t_data *data);
int		finish_simulation(t_data *data);
void	wait_threads(t_data *data);
bool	sim_finished(t_data *data);

// utils

long	current_time(void);
void	sleep_ms(long time, t_data *data);
void	print_status(t_philo *philo, char *status);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);

// error

void	error_full(t_data *data, char *msg);
void	error_exit(t_data *data, char *msg);

// init

void	init_data(t_data *data, char **argv);

// set_get

void	increase_int(pthread_mutex_t *mutex, int *val);
void	set_bool(pthread_mutex_t *mutex, bool *dest, bool val);
void	set_long(pthread_mutex_t *mutex, long *dest, long val);
long	get_long(pthread_mutex_t *mutex, long *val);
bool	get_bool(pthread_mutex_t *mutex, bool *val);

// main

void	clean_up(t_data *data);
void	destroy_mutexes(t_data *data);

// philo

void	*philo_routine(void *arg);

// monitor

bool	threads_ready(pthread_mutex_t *mutex, int *threads, int philo_num);
void	*monitor_routine(void *arg);

#endif
