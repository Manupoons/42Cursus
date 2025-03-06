/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:58:31 by mamaratr          #+#    #+#             */
/*   Updated: 2025/03/06 12:03:02 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(t_data *data, char *msg)
{
	printf("%s\n", msg);
	if (data)
	{
		destroy_mutex(data);
		clean_up(data);
	}
	exit(EXIT_FAILURE);
}

void	error_exit(t_data *data, char *msg)
{
	printf("%s\n", msg);
	if (data)
		clean_up(data);
	exit(1);
}