/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:42:30 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/02 12:48:18 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	is_biggest(t_stack *target, int n)
{
	t_node	*node;
	
	if (!target->top)
		return (INT_MIN);
	node = target->top;
	while (node)
	{
		if (n < node->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	is_smallest(t_stack *target, int n)
{
	t_node	*node;
	
	if (!target->top)
		return (INT_MIN);
	node = target->top;
	while (node)
	{
		if (n > node->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	get_biggest(t_stack *target)
{
	t_node	*node;
	int		max;
	
	if (!target->top)
		return (INT_MIN);
	node = target->top;
	max = node->value;
	while (node)
	{
		if (max < node->value)
			max = node->value;
		node = node->next;
	}
	return (max);
}

int	get_smallest(t_stack *target)
{
	t_node	*node;
	int		min;
	
	if (!target->top)
		return (INT_MIN);
	node = target->top;
	min = node->value;
	while (node)
	{
		if (min > node->value)
			min = node->value;
		node = node->next;
	}
	return (min);
}