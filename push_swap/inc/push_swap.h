/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:54:51 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/02 12:38:36 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

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

int					max(int a, int b);
int					ft_atoi(char *str);
int					ft_strlen(char *str);
int					ft_strncmp(char *s1, char *s2, size_t n);
int					is_sorted(t_stack *stack);
int					ft_isdigit(int c);
int					validate_input(char *str);
int					validate_params(int argc, char **argv);
int					duplicates(t_stack *stack);
int					is_biggest(t_stack *to_search, int n);
int					is_smallest(t_stack *to_search, int n);
int					check_cheapest(t_stack *from, t_stack *to);
int					check_cheapest(t_stack *from, t_stack *to);
int					get_depth(t_stack *from, int n);
int					get_biggest(t_stack *to_search);
int					get_target(t_stack *to_search, int n, int u_or_l);
int					get_immediate_lower(t_stack *to_search, int n);
int					get_immediate_upper(t_stack *to_search, int n);
int					push_cheapest(t_stack *from, t_stack *to, int n);
char				*ft_strdup(char *s1);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(char *s, unsigned int st, size_t len);
void				*ft_calloc(size_t count, size_t size);
char				**ft_split(char *s, char c);
void				error(void);
void				free_stack(t_stack *stack);
void				ft_free_split(char **split);
void				push_back(t_stack *from, t_stack *to);
void				push_stack(t_stack *stack, int value);
void				print_stacks(t_stack *stack_a, t_stack *stack_b);
void				init_stack(int argc, char **argv, t_stack *stack);
void				bring_to_top(t_stack *a, int target);
void				bring_min_to_top(t_stack *stack);
void				sort(t_stack *a, t_stack *b);
void				sort_two(t_stack *a);
void				sort_three(t_stack *a);
void				sa(t_stack *a);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
t_node				*new_node(int value);
t_stack				*new_stack(void);
unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);

int					get_smallest(t_stack *to_search);
int					empty_string(const char *str);
int					valid_int_range(char *str);

#endif