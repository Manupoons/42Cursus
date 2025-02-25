/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:45:27 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/25 12:11:27 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

static void	handle_bigger_first(t_stack *stack)
{
	if (stack->top->next->value < stack->top->next->next->value)
		ra(stack);
	else
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_two(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return ;
	if (stack->top->value > stack->top->next->value)
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->top->value;
	second = stack->top->next->value;
	third = stack->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && first > third)
		handle_bigger_first(stack);
	else if (first < second && first > third)
		rra(stack);
	else if (first < second && second > third)
	{
		sa(stack);
		ra(stack);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	int	num;

	num = INT_MIN;
	if (a->size == 2)
	{
		sort_two(a);
		return ;
	}
	if (a->size >= 4)
		pb(a, b);
	while (a->size > 3)
	{
		num = get_cheapest(a, b);
		push_cheapest(a, b, num);
	}
	sort_three(a);
	if (b->size != 0)
	{
		push_back(b, a);
		move_min_top(a);
	}
	return ;
}
