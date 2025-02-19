/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:54:51 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/19 16:22:12 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../Libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

//MOVES:

void				sa(t_stack *a);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

//SORT:

// get_cheapest
int					get_cheapest(t_stack *stack, t_stack *target);

// get_target

int					get_target(t_stack *target, int n, int u_or_l);
int					get_closer_smaller(t_stack *target, int n);
int					get_closer_bigger(t_stack *target, int n);

// push_cheapest

int					push_cheapest(t_stack *from, t_stack *to, int n);

// size_info

int					is_biggest(t_stack *target, int n);
int					is_smallest(t_stack *target, int n);
int					get_biggest(t_stack *target);
int					get_smallest(t_stack *target);

// sort

void				sort(t_stack *a, t_stack *b);
void				sort_two(t_stack *a);
void				sort_three(t_stack *a);

// utils

int					get_depth(t_stack *from, int n);
void				move_top(t_stack *stack, int n);
void				move_min_top(t_stack *stack);
int					is_sorted(t_stack *stack);
void				push_back(t_stack *from, t_stack *to);

//UTILS

//errors_check

void				error(void);
int					has_duplicates(t_stack *stack);
int					valid_int_range(char *str);
int					check_errors(int argc, char **argv);

//stack_manager

void				free_stack(t_stack *stack);
void				push_stack(t_stack *stack, int value);
void				init_stack(int argc, char **argv, t_stack *stack);
t_node				*new_node(int value);
t_stack				*new_stack(void);

//validate_input

int					validate_input(char *str);
int					validate_params(int argc, char **argv);

#endif