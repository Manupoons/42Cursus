/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:06:16 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/11 13:06:17 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_exit(t_list *d, char letter)
{
	if (letter == 'E' && d->consum == 0)
	{
		write(1, "Congrats, you win 🥳🏆\n", 27);
		ft_free(d);
	}
	if (letter == 'E' && d->consum != 0)
	{
		write(1, "Necesitas recoger todos los consumibles!\n", 41);
		return (1);
	}
	else
		return (0);
}
