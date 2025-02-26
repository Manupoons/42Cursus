/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:52:20 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/26 19:19:13 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	has_duplicates(t_stack *a)
{
	t_node	*node;
	t_node	**seen_values;
	int		i;
	int		j;

	seen_values = malloc(sizeof(t_node *) * a->size);
	if (!seen_values)
		return (1);
	node = a->top;
	i = 0;
	while (node != NULL)
	{
		j = 0;
		while (j < i)
		{
			if (seen_values[j]->value == node->value)
				return (free(seen_values), 1);
			j++;
		}
		seen_values[i] = node;
		i++;
		node = node->next;
	}
	return (free(seen_values), 0);
}

static int	is_sorted(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (1);
	node = stack->top;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	check_errors(int argc, char **argv)
{
	int		i;
	int		j;
	char	**numbers;

	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			return (1);
		j = 0;
		while (numbers[j])
		{
			if (!valid_int_range(numbers[j]))
				return (ft_free_split(numbers), 1);
			j++;
		}
		ft_free_split(numbers);
		i++;
	}
	if (!validate_params(argc, argv))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (check_errors(argc, argv))
		error();
	a = new_stack();
	b = new_stack();
	if (!a || !b)
	{
		free_stack(a);
		free_stack(b);
		error();
	}
	init_stack(argc, argv, a);
	if (has_duplicates(a))
	{
		free_stack(a);
		free_stack(b);
		error();
	}
	if (!is_sorted(a))
		sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
