#include "philo.h"

void	full_error(t_data *data, char *msg)
{
	printf("%s\n", msg);
	if (data)
	{
		//destroy_mutex(data);
		//clean(data);
	}
	exit(EXIT_FAILURE);
}

void	error(t_data *data, char *msg)
{
	printf("%s\n", msg);
	if (data)
		//clean(data);
	exit(EXIT_FAILURE);
}
