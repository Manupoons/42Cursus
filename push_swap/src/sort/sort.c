/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:45:27 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/03 17:13:53 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	handle_bigger_first(t_stack *stack)
{
	if (stack->top->next->value < stack->top->next->next->value)
		ra(stack);
	else
	{
		sa(stack);
		ra(stack);
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
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && first > third)
		handle_bigger_first(stack);
	else if (first < second && first > third)
		rra(stack);
	else if (first < second && second > third)
		sa(stack);
		ra(stack);
}

void	sort(t_stack *a, t_stack *b)
{
	int	num;

	num = INT_MAX;
	if (a->size == 2)
	{
		sort_two(a);
		return ;
	}
	if (a->size >= 4)
		pb(a, b);
//	if (a->size >= 5)
//		pb(a, b);
	while (a->size > 3)
	{
		num = check_cheapest(a, b);
		push_cheapest(a, b, num);
	}
	sort_three(a);
	if (b->size != 0)
	{
		push_back(b, a);
		bring_min_to_top(a);
	}
	return ;
}