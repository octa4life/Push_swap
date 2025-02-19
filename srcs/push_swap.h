/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:28:12 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/04 17:55:09 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// Part of Errors
int						p_error_syntax(char *str_n);
int						p_error_duplicate(t_stack_node *stack_a, int n);
void					p_free_stack(t_stack_node **stack);
void					p_free_errors(t_stack_node **a);

// ui
void					current_index(t_stack_node *stack);
t_stack_node			*ft_check_cheapest(t_stack_node *stack);
void					init_nodes_a(t_stack_node *stack_a,
							t_stack_node *stack_b);
void					sort_stacks(t_stack_node **a, t_stack_node **b);
void					sort_three(t_stack_node **a);
char					**my_split(char *s, char c);
void					stack_init(t_stack_node **a, char **argv);
int						stack_len(t_stack_node *stack);
t_stack_node			*find_last(t_stack_node *stack);
bool					stack_sorted(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);
void					init_stack_a(t_stack_node **a, char **argv);
void					prep_for_push(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
void					free_split(char **argv);

// Part of Commands
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					rev_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
// swap.c
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);

// push.c
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);

// rotate.c
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);

// reverse_rotate.c
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);


#endif
