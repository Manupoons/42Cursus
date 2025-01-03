/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:25:22 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/03 17:41:48 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	get_target(t_stack *target, int n, int dir)
{
	if (is_biggest(target, n) || is_smallest(target, n))
		return (get_biggest(target));
	else if (dir)
		return (get_closer_smaller(target, n));
	else if (!dir)
		return (get_closer_bigger(target, n));
	else
		return (INT_MIN);
}

int	get_closer_smaller(t_stack *target, int n)
{
	int		dif;
	int		val;
	t_node	*node;

	if(!target->top)
		return (INT_MIN);
	node = target->top;
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

int	get_closer_bigger(t_stack *target, int n)
{
	int		dif;
	int		closest_dif;
	int		val;
	t_node	*node;

	if(!target->top || !target)
		return (INT_MIN);
	node = target->top;
	closest_dif = INT_MAX;
	val = INT_MIN;
	if (is_biggest(target, n))
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