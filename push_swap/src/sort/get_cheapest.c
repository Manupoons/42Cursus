/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:31:13 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/19 09:49:13 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_moves(t_stack *stack, t_stack *obj, int val)
{
	int	depth;
	int	target;
	int	target_depth;
	int	moves;

	depth = get_depth(stack, val);
	target = get_target(obj, val, 1);
	target_depth = get_depth(obj, target);
	if ((depth > 0 && target_depth > 0) || (depth < 0 && target_depth < 0))
		moves = max(abs(depth), abs(target_depth));
	else
		moves = abs(depth) + abs(target_depth);
	return (moves);
}

int	get_cheapest(t_stack *stack, t_stack *target)
{
	t_node	*node;
	int		val;
	int		steps;
	int		moves;

	node = stack->top;
	steps = INT_MAX;
	val = INT_MIN;
	while (node)
	{
		moves = get_moves(stack, target, node->value);
		if (moves < steps)
		{
			steps = moves;
			val = node->value;
		}
		node = node->next;
	}
	return (val);
}
