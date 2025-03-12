#ifndef PHILO_H
# define PHILO_H

#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_philo
{
	int			id;
	int			meals_eaten;
	long		last_meal_time;
	pthread_t	philo_thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;


typedef struct s_data
{
	int				num_philo;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				meals_eat;
	pthread_t		monitor_thread;
	pthread_mutex_t	threads_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_mutex;
	t_philo			*philos;
}	t_data;

long get_current_time(void);
void *philosopher_routine(void *arg);

#endif
