/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:16:49 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/02 11:58:46 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	node = stack->bottom;
	while (node)
	{
		temp = node;
		node = node->prev;
		free(temp);
	}
	free(stack);
}

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*new_stack(void)
{
	t_stack	*stack;
	
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

void	push_stack(t_stack *stack, int value)
{
	t_node	*node;
	
	node = new_node(value);
	if (!node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->next = stack->top;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

void	init_stack(int argc, char **argv, t_stack *stack)
{
	int		i;
	char	**numbers;
	
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		i = 0;
		while (numbers[i])
			i++;
		while (i > 0)
		{
			i--;
			push_stack(stack, ft_atoi(numbers[i]));
		}
		ft_free_split(numbers);
	}
	else
	{
		i = argc - 1;
		while (i > 0)
		{
			push_stack(stack, ft_atoi(argv[i]));
			i--;
		}
	}
}