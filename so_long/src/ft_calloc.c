/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:06:07 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/11 13:06:11 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*bzero;

	bzero = (void *)malloc(count * size);
	if (!bzero)
		return (0);
	ft_bzero (bzero, count * size);
	return (bzero);
}
