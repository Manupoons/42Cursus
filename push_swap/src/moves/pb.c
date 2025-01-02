/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:15:59 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/28 11:22:36 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (a->top == NULL)
		return ;
	node = a->top;
	a->top = node->next;
	if (a->top == NULL)
		a->bottom = NULL;
	else
		a->top->prev = NULL;
	node->next = b->top;
	if (b->top == NULL)
		b->bottom = node;
	else
		b->top->prev = node;
	b->top = node;
	node->prev = NULL;
	b->size++;
	a->size--;
	write(1, "pb\n", 3);
}