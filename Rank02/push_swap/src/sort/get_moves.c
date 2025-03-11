/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:25:22 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/26 13:58:18 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	get_closer_smaller(t_stack *stack, int n)
{
	t_node	*node;
	int		dif;
	int		closest_dif;
	int		val;

	if (!stack->top)
		return (INT_MIN);
	node = stack->top;
	closest_dif = INT_MAX;
	val = INT_MIN;
	if (is_smallest(stack, n))
		return (INT_MIN);
	while (node)
	{
		dif = n - node->value;
		if (dif > 0 && dif < closest_dif)
		{
			closest_dif = dif;
			val = node->value;
		}
		node = node->next;
	}
	return (val);
}

int	get_closer_bigger(t_stack *stack, int n)
{
	t_node	*node;
	int		dif;
	int		closest_dif;
	int		val;

	if (!stack->top || !stack)
		return (INT_MIN);
	node = stack->top;
	closest_dif = INT_MAX;
	val = INT_MIN;
	if (is_biggest(stack, n))
		return (INT_MAX);
	while (node)
	{
		dif = node->value - n;
		if (dif > 0 && dif < closest_dif)
		{
			closest_dif = dif;
			val = node->value;
		}
		node = node->next;
	}
	return (val);
}

int	get_target(t_stack *stack, int n)
{
	if (is_biggest(stack, n) || is_smallest(stack, n))
		return (get_biggest(stack));
	return (get_closer_smaller(stack, n));
}

int	get_depth(t_stack *stack, int n)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack->top;
	while (node)
	{
		if (node->value == n)
		{
			if (i <= stack->size / 2)
				return (i);
			else
				return (i - stack->size);
		}
		i++;
		node = node->next;
	}
	return (INT_MIN);
}

int	get_moves(t_stack *a, t_stack *b, int n)
{
	int	depth;
	int	target;
	int	target_depth;
	int	moves;

	depth = get_depth(a, n);
	target = get_target(b, n);
	target_depth = get_depth(b, target);
	if ((depth > 0 && target_depth > 0) || (depth < 0 && target_depth < 0))
		moves = ft_max(ft_abs(depth), ft_abs(target_depth));
	else
		moves = ft_abs(depth) + ft_abs(target_depth);
	return (moves);
}
