#include "philo.h"

int init_philos(t_data *data)
{

}

int init_mutexes(t_data *data)
{

}

void	init_data(t_data *data, char **argv)
{
	data->forks = NULL;
	data->philos = NULL;
	data->num_philo = ft_atoi(argv[1]);
}
