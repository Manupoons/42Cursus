/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:34:12 by mamaratr          #+#    #+#             */
/*   Updated: 2025/03/14 15:03:02 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	validate_input(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		error(NULL, "Error: Invalid number of arguments");
	i = 1;
	while (i < argc)
	{
		j = ft_atoi(argv[i]);
		if (j == 0)
			error(NULL, "Error: Invalid argument");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	validate_input(argc, argv);
	init_data(&data, argv);
	if (start_simulation(&data) != 0)
		full_error(&data, "Error creating threads");
	if (end_simulation(&data) != 0)
		full_error(&data, "Error joining threads");
	destroy_mutexes(&data);
	free_data(&data);
	return (EXIT_SUCCESS);
}
