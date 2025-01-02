/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:16:08 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/28 11:29:19 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rra(t_stack *a)
{
	t_node	*node;

	if (!a->top || a->top == a->bottom)
		return ;
	node = a->bottom;
	a->bottom = node->prev;
	a->bottom->next = NULL;
	node->prev = NULL;
	node->next = a->top;
	a->top->prev = node;
	a->top = node;
	write(1, "rra\n", 4);
}