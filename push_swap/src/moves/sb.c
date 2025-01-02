/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:14:58 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/28 11:15:54 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if(!b->top || b->top == b->bottom)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	b->top = second;
	first->prev = second;
	write(1, "sb\n", 3);
}