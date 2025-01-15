/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:16:01 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/15 17:39:15 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ra(t_stack *a)
{
	t_node	*node;

	if (!a->top || a->top == a->bottom)
		return ;
	node = a->top;
	a->top = node->next;
	a->top->prev = NULL;
	a->bottom->next = node;
	node->prev = a->bottom;
	node->next = NULL;
	a->bottom = node;
	write(1, "ra\n", 3);
}
