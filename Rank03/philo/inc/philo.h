/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:18:53 by mamaratr          #+#    #+#             */
/*   Updated: 2025/03/28 12:02:41 by mamaratr         ###   ########.fr       */
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

// INIT
void	init_data(t_data *data, char **argv);

// ERRORS
void	destroy_mutexes(t_data *data);
void	free_data(t_data *data);
void	full_error(t_data *data, char *msg);
void	error(t_data *data, char *msg);

// UTILS
long	get_current_time(void);
void	sleep_ms(long time, t_data *data);
int		ft_strcmp(const char *s1, const char *s2);
void	print_status(t_philo *philo, char *status);
int		ft_atoi(const char *str);

// SET GET
void	set_bool(pthread_mutex_t *mutex, bool *var, bool value);
void	set_long(pthread_mutex_t *mutex, long *var, long value);
bool	get_bool(pthread_mutex_t *mutex, bool *var);
long	get_long(pthread_mutex_t *mutex, long *var);
void	increase_int(pthread_mutex_t *mutex, int *value);

// SIMULATION
bool	sim_finished(t_data *data);
void	wait_threads(t_data *data);
int		end_simulation(t_data *data);
int		start_simulation(t_data *data);

// MONITOR
bool	threads_ready(pthread_mutex_t *mutex, int *threads, int philo_num);
void	*monitor_routine(void *arg);

// PHILO
void	*philo_routine(void *arg);

#endif