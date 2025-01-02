/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:55:37 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/28 11:09:55 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if(!a->top || a->top == a->bottom)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	a->top = second;
	first->prev = second;
	write(1, "sa\n", 3);
}