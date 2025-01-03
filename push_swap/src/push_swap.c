/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:52:20 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/03 17:51:46 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (check_errors(argc, argv))
		error();
	a = new_stack();
	b = new_stack();
	if (!a || !b)
		error();
	init_stack(argc, argv, a);
	if (has_duplicates(a))
		error();
	if (!is_sorted(a))
		sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}