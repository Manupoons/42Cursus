/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:29:28 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/18 13:43:57 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(stack_a, stack_b);
	}
}

static void	rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(stack_a, stack_b);
	}
}

static void	rotate_a(t_stack **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(stack_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(stack_a);
			(*cost)++;
		}
	}
	
}

static void	rotate_b(t_stack **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(stack_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(stack_b);
			(*cost)++;
		}
	}
}

void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		reverse_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	rotate_a(stack_a, &cost_a);
	rotate_b(stack_b, &cost_b);
	do_pa(stack_a, stack_b);
}