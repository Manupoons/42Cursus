/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:25:59 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/26 12:37:31 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	move_top(t_stack *a, int n)
{
	int	depth;

	depth = get_depth(a, n);
	while (depth != 0)
	{
		if (depth < 0)
		{
			rra(a);
			depth++;
		}
		if (depth > 0)
		{
			ra(a);
			depth--;
		}
	}
}

void	move_min_top(t_stack *a)
{
	int	val;

	if (!a || !a->top)
		return ;
	val = get_smallest(a);
	move_top(a, val);
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
		if (target == INT_MAX || target == INT_MIN)
			target = get_smallest(a);
		move_top(a, target);
		pa(a, b);
		node = node->next;
	}
}
