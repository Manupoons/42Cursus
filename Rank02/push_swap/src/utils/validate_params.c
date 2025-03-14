/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:27:27 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/26 19:27:48 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

static int	validate_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	validate_single_input(char *input)
{
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(input, ' ');
	if (!numbers)
		return (0);
	while (numbers[i])
	{
		if (!validate_input(numbers[i]))
			return (ft_free_split(numbers), 0);
		i++;
	}
	ft_free_split(numbers);
	return (1);
}

static int	validate_multiple_inputs(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!validate_input(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_params(int argc, char **argv)
{
	if (argc == 2)
		return (validate_single_input(argv[1]));
	return (validate_multiple_inputs(argc, argv));
}
