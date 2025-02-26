/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:43:10 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/26 13:56:06 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_a(t_stack *a, int *depth)
{
	if (*depth > 0)
	{
		ra(a);
		(*depth)--;
	}
	else if (*depth < 0)
	{
		rra(a);
		(*depth)++;
	}
}

static void	rotate_b(t_stack *b, int *trgt_depth)
{
	if (*trgt_depth > 0)
	{
		rb(b);
		(*trgt_depth)--;
	}
	else if (*trgt_depth < 0)
	{
		rrb(b);
		(*trgt_depth)++;
	}
}

static void	rotate_both(t_stack *a, t_stack *b, int *depth, int *trgt_depth)
{
	if (*depth > 0 && *trgt_depth > 0)
	{
		rr(a, b);
		(*depth)--;
		(*trgt_depth)--;
	}
	else if (*depth < 0 && *trgt_depth < 0)
	{
		rrr(a, b);
		(*depth)++;
		(*trgt_depth)++;
	}
}

int	get_cheapest(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		val;
	int		steps;
	int		moves;

	node = a->top;
	steps = INT_MAX;
	val = INT_MIN;
	while (node)
	{
		moves = get_moves(a, b, node->value);
		if (moves < steps)
		{
			steps = moves;
			val = node->value;
		}
		node = node->next;
	}
	return (val);
}

int	push_cheapest(t_stack *a, t_stack *b, int n)
{
	int	depth;
	int	target;
	int	trgt_depth;

	depth = get_depth(a, n);
	target = get_target(b, n);
	trgt_depth = get_depth(b, target);
	while (depth != 0 || trgt_depth != 0)
	{
		if ((depth > 0 && trgt_depth > 0) || (depth < 0 && trgt_depth < 0))
			rotate_both(a, b, &depth, &trgt_depth);
		else
		{
			rotate_a(a, &depth);
			rotate_b(b, &trgt_depth);
		}
	}
	return (pb(a, b), 0);
}
