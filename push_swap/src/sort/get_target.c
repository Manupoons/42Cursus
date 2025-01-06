/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:25:22 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/06 12:03:40 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	get_target(t_stack *stack, int n, int dir)
{
	if (is_biggest(stack, n) || is_smallest(stack, n))
		return (get_biggest(stack));
	else if (dir)
		return (get_closer_smaller(stack, n));
	else if (!dir)
		return (get_closer_bigger(stack, n));
	else
		return (INT_MIN);
}

int	get_closer_smaller(t_stack *stack, int n)
{
	t_node	*node;
	int		dif;
	int		val;

	if(!stack->top)
		return (INT_MIN);
	node = stack->top;
	dif = INT_MAX;
	val = INT_MIN;
	while (node)
	{
		if (n - node->value < dif && n - node->value > 0)
		{
			dif = n - node->value;
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

	if(!stack->top || !stack)
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