/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:06:37 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/11 13:06:39 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

int	ft_free(t_list *d)
{
	d->errors = 1;
	if (d->big_line)
		free(d->big_line);
	if (d)
		free(d);
	exit(0);
}