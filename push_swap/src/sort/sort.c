/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:45:27 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/26 13:56:00 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_two(t_stack *a)
{
	if (!a || !a->top || !a->top->next)
		return ;
	if (a->top->value > a->top->next->value)
		sa(a);
}

static void	handle_bigger_first(t_stack *a)
{
	if (a->top->next->value < a->top->next->next->value)
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && first > third)
		handle_bigger_first(a);
	else if (first < second && first > third)
		rra(a);
	else if (first < second && second > third)
	{
		sa(a);
		ra(a);
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
