/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:16:06 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/03 17:40:09 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rr(t_stack *a, t_stack *b)
{
	t_node	*node;
	t_node	*node2;

	if (!a->top || a->top == a->bottom)
		return ;
	node = a->top;
	a->top = node->next;
	a->top->prev = NULL;
	a->bottom->next = node;
	node->prev = a->bottom;
	node->next = NULL;
	a->bottom = node;
	if (!b->top || b->top == b->bottom)
		return ;
	node2 = b->top;
	b->top = node2->next;
	b->top->prev = NULL;
	b->bottom->next = node2;
	node2->prev = b->bottom;
	node2->next = NULL;
	b->bottom = node2;
	write(1, "rr\n", 3);
}