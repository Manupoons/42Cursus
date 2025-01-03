/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:25:59 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/03 17:42:31 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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
				return (1);
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

int	is_sorted(t_stack *stack)
{
	t_node	*node;
	
	if (!stack || !stack->top)
		return (1);
	node = stack->top;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
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