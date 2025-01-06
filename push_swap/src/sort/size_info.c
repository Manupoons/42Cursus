/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:42:30 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/06 11:57:57 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	is_biggest(t_stack *stack, int n)
{
	t_node	*node;
	
	if (!stack->top)
		return (INT_MIN);
	node = stack->top;
	while (node)
	{
		if (n < node->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	is_smallest(t_stack *stack, int n)
{
	t_node	*node;
	
	if (!stack->top)
		return (INT_MIN);
	node = stack->top;
	while (node)
	{
		if (n > node->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	get_biggest(t_stack *stack)
{
	t_node	*node;
	int		max;
	
	if (!stack->top)
		return (INT_MIN);
	node = stack->top;
	max = node->value;
	while (node)
	{
		if (max < node->value)
			max = node->value;
		node = node->next;
	}
	return (max);
}

int	get_smallest(t_stack *stack)
{
	t_node	*node;
	int		min;
	
	if (!stack->top)
		return (INT_MAX);
	node = stack->top;
	min = node->value;
	while (node)
	{
		if (min > node->value)
			min = node->value;
		node = node->next;
	}
	return (min);
}