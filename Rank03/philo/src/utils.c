#include "philo.h"

long get_current_time(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int	ft_atoi(const char *str)
{
	long	res;

	res = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + *str - '0';
		if (res > INT_MAX)
			error_exit(NULL, "Error: Integer overflow");
		str++;
	}
	return ((int)res);
}
