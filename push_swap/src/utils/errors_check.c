/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:06:55 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/19 16:15:24 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	has_duplicates(t_stack *stack)
{
	t_node	*node1;
	t_node	**seen_values;
	int		i;
	int		j;

	seen_values = malloc(sizeof(t_node *) * stack->size);
	if (!seen_values)
		return (1);
	node1 = stack->top;
	i = 0;
	while (node1 != NULL)
	{
		j = 0;
		while (j < i)
		{
			if (seen_values[j]->value == node1->value)
				return (free(seen_values), 1);
			j++;
		}
		seen_values[i] = node1;
		i++;
		node1 = node1->next;
	}
	return (free(seen_values), 0);
}

int	valid_int_range(char *str)
{
	if (*str == '-')
	{
		if (ft_strlen(str) > 11 || (ft_strlen(str) == 11 && ft_strncmp(str,
					"-2147483648", ft_strlen(str)) > 0))
			return (0);
	}
	else
	{
		if (ft_strlen(str) > 10 || (ft_strlen(str) == 10 && ft_strncmp(str,
					"2147483647", ft_strlen(str)) > 0))
			return (0);
	}
	return (1);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	check_errors(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!valid_int_range(argv[i]))
			return (1);
		i++;
	}
	if (!validate_params(argc, argv))
		return (1);
	return (0);
}
