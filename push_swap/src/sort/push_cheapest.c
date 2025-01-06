/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:43:10 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/06 11:52:38 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_stack_obj(t_stack *stack, int *depth)
{
	if (*depth > 0)
	{
		ra(stack);
		(*depth)--;
	}
	else if (*depth < 0)
	{
		rra(stack);
		(*depth)++;
	}
}

static void	rotate_target_obj(t_stack *stack, int *depth)
{
	if (*depth > 0)
	{
		rb(stack);
		(*depth)--;
	}
	else if (*depth < 0)
	{
		rrb(stack);
		(*depth)++;
	}
}

static void	rotate_both(t_stack *stack, t_stack *obj, int *depth, int *target_depth)
{
	if (*depth > 0 && *target_depth > 0)
	{
		rr(stack, obj);
		(*depth)--;
		(*target_depth)--;
	}
	else if (*depth < 0 && *target_depth < 0)
	{
		rrr(stack, obj);
		(*depth)++;
		(*target_depth)++;
	}
}

int	push_cheapest(t_stack *stack, t_stack *obj, int n)
{
	int	depth;
	int	target;
	int	target_depth;

	depth = get_depth(stack, n);
	target = get_target(obj, n, 1);
	target_depth = get_depth(obj, target);
	while (depth != 0 || target_depth != 0)
	{
		if ((depth > 0 && target_depth > 0) || (depth < 0 && target_depth < 0))
			rotate_both(stack, obj, &depth, &target_depth);
		else
		{
			rotate_stack_obj(stack, &depth);
			rotate_target_obj(obj, &target_depth);
		}
	}
	return (pb(stack, obj), 0);
}
