/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:38:41 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/18 13:09:44 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	get_position(t_stack **stack)
{
	t_stack	*temp;
	int	i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

static int	get_target(t_stack **stack_a, int index_b, int target_i, int target)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp)
	{
		if (temp->index > index_b && temp->index < target_i)
		{
			target_i = temp->index;
			target = temp->pos;
		}
		temp = temp->next;
	}
	if (target_i != INT_MAX)
		return (target);
	temp = *stack_a;
	while (temp)
	{
		if (temp->index < target_i)
		{
			target_i = temp->index;
			target = temp->pos;
		}
		temp = temp->next;
	}
	return (target);
}

int	position_lowest_index(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_i;
	int		lowest_p;

	temp = *stack;
	lowest_i = INT_MAX;
	get_position(stack);
	lowest_p = temp->pos;
	while (temp)
	{
		if (temp->index < lowest_i)
		{
			lowest_i = temp->index;
			lowest_p = temp->pos;
		}
		temp = temp->next;
	}
	return (lowest_p);
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		target;
	
	temp = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	target = 0;
	while (temp)
	{
		target = get_target(stack_a, temp->index, INT_MAX, target);
		temp->target = target;
		temp = temp->next;
	}
}
