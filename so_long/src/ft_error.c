/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:05:56 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/01 19:50:27 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

void	ft_error(t_list *d, int num)
{
	write(1, "Error\n", 6);
	if (num == 1)
		write(1, "En el principio de linea no hay pared\n", 3);
	if (num == 2)
		write(1, "En el final de linea no hay pared\n", 34);
	if (num == 3)
		write(1, "En la primera linea no hay pared\n", 33);
	if (num == 4)
		write(1, "En la ultima linea no hay pared\n", 32);
	if (d->consum < 1 && num == 5)
		write(1, "No hay consumibles!\n", 20);
	if (d->player != 1 && num == 5)
		write(1, "El mapa solo debe tener un personaje\n", 37);
	if (d->ex < 1 && num == 5)
		write(1, "El mapa debe contener una salida\n", 33);
	if (num == 6)
		write(1, "El fichero no tiene la extension correcta\n", 42);
	if (num == 7)
		write(1, "El mapa no es rectangular\n", 27);
	if (num == 8)
		write(1, "El mapa contiene caracteres erroneos\n", 37);
	if (num == 9)
		write(1, "El mapa no es rectangular\n", 26);
	ft_free(d);
}
