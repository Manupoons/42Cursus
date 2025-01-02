/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:16:02 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/28 11:25:28 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rb(t_stack *b)
{
	t_node	*node;

	if (!b->top || b->top == b->bottom)
		return ;
	node = b->top;
	b->top = node->next;
	b->top->prev = NULL;
	b->bottom->next = node;
	node->prev = b->bottom;
	node->next = NULL;
	b->bottom = node;
	write(1, "rb\n", 3);
}