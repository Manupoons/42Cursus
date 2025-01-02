/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:15:57 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/28 11:21:31 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (b->top == NULL)
		return ;
	node = b->top;
	b->top = node->next;
	if (b->top == NULL)
		b->bottom = NULL;
	else
		b->top->prev = NULL;
	node->next = a->top;
	if (a->top == NULL)
		a->bottom = node;
	else
		a->top->prev = node;
	a->top = node;
	node->prev = NULL;
	a->size++;
	b->size--;
	write(1, "pa\n", 3);
}