/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:25:59 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/19 17:18:20 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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
		moves = ft_max(ft_abs(depth), ft_abs(target_depth));
	else
		moves = ft_abs(depth) + ft_abs(target_depth);
	return (moves);
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

void	move_top(t_stack *stack, int n)
{
	int	depth;

	depth = get_depth(stack, n);
	while (depth != 0)
	{
		if (depth < 0)
		{
			rra(stack);
			depth++;
		}
		if (depth > 0)
		{
			ra(stack);
			depth--;
		}
	}
}

void	move_min_top(t_stack *stack)
{
	int	val;

	if (!stack || !stack->top)
		return ;
	val = get_smallest(stack);
	move_top(stack, val);
}

void	push_back(t_stack *b, t_stack *a)
{
	t_node	*node;
	int		target;

	node = b->top;
	while (node)
	{
		if (b->top == NULL)
			break ;
		node = b->top;
		target = get_closer_bigger(a, node->value);
		if (target == INT_MAX)
			target = get_smallest(a);
		move_top(a, target);
		pa(a, b);
		node = node->next;
	}
}
