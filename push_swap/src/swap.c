/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:36:07 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/18 12:22:38 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack *temp;

	if (!*stack || (*stack)->next == NULL) 
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	do_sa(t_stack **stack_a){
	swap(stack_a);
	ft_putstr("sa\n");
}

void	do_sb(t_stack **stack_b){
	swap(stack_b);
	ft_putstr("sb\n");
}

void	do_ss(t_stack **stack_a, t_stack **stack_b){
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}