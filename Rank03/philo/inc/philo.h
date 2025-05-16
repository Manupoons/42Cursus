/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:18:53 by mamaratr          #+#    #+#             */
/*   Updated: 2025/05/16 12:54:33 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define HELP_MSG "Usage: ./philo <number_of_philosophers> <time_to_die> \
<time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]"

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		philo_thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				num_philos;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				meals_count;
	int				philo_ready;
	int				philo_full;
	long			start_time;
	bool			sim_finished;
	bool			threads_ready;
	pthread_t		monitor_thread;
	pthread_mutex_t	threads_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_mutex;
	t_philo			*philos;
}	t_data;

// simulation

bool	sim_finished(t_data *data);
void	wait_threads(t_data *data);
int		end_simulation(t_data *data);
void	*philo_routine(void *arg);
int		start_simulation(t_data *data);

// utils

long	get_current_time(void);
void	sleep_ms(long time, t_data *data);
int		ft_strcmp(const char *s1, const char *s2);
void	print_status(t_philo *philo, char *status);
int		ft_atoi(const char *str);

// error

void	destroy_mutexes(t_data *data);
void	free_data(t_data *data);
void	full_error(t_data *data, char *msg);
void	error(t_data *data, char *msg);

// init

void	init_data(t_data *data, char **argv);

// set_get

void	set_long(pthread_mutex_t *mutex, long *value, long new_value);
void	set_bool(pthread_mutex_t *mutex, bool *value, bool new_value);
bool	get_bool(pthread_mutex_t *mutex, bool *value);
void	increase_int(pthread_mutex_t *mutex, int *value);

// philo_life

void	*one_philo(t_philo *philo, t_data *data);
void	philo_eat(t_philo *philo, t_data *data);
void	philo_sleep(t_philo *philo, t_data *data);
void	philo_think(t_philo *philo, t_data *data);

// monitor

void	*monitor_routine(void *arg);

#endif