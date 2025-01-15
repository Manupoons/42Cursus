/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:06:55 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/15 17:42:44 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	has_duplicates(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	node1 = stack->top;
	while (node1 != NULL)
	{
		node2 = node1->next;
		while (node2 != NULL)
		{
			if (node1->value == node2->value)
				return (1);
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return (0);
}

int	empty_string(const char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (!ft_isspace((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
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
					"2147483648", ft_strlen(str)) > 0))
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
	if (argc > 1 && empty_string(argv[1]))
		return (1);
	if (argc == 1)
		return (1);
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
