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

typedef struct	s_stack_node
{
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
}	t_stack_node;

// Part of Errors
int						p_error_syntax(char *str_n);
int						p_error_duplicate(t_stack_node *stack_a, int n);
void					p_free_stack(t_stack_node **stack);
void					p_free_errors(t_stack_node **a);

// Part Stack initiation
void					current_i(t_stack_node *stack);
//static void			set_target_a(t_stack_node *stack_a, t_stack_node *stack_b);
//static void			cost_check_a(t_stack_node *stack_a, t_stack_node *stack_b);
void					*ft_check_cheapest(t_stack_node *stack);
void					init_nodes_a(t_stack_node *stack_a, t_stack_node *stack_b);
void					before_push(t_stack_node **stack,t_stack_node *top_node,char stack_name);
void					rotate_both(t_stack_node **stack_a,t_stack_node **stack_b,t_stack_node *cheapest_n);
void					rev_rotate_both(t_stack_node **stack_a,t_stack_node **stack_b,t_stack_node *cheapest_n);
void					move_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b);
void					move_b_to_a(t_stack_node **a, t_stack_node **b);
void					min_on_top(t_stack_node **a);
void					sort_stacks(t_stack_node **a, t_stack_node **b);
void					sort_three(t_stack_node **a);
//static int			countw(char *s, char c);
//static char			*get_nextw(char *s, char c);
char					**my_split(char *s, char c);
//static long				ft_atol(const char *nptr);
//static void				append_node(t_stack_node **stack);
void					stack_init(t_stack_node **a, char **argv);
int						stack_len(t_stack_node *stack);
t_stack_node			*find_last(t_stack_node *stack);
bool					stack_sorted(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);
void				init_nodes_b(t_stack_node *a, t_stack_node *b);



// Part of Stack Utils

// Part of Commands
//static void			push(t_stack_node **dest, t_stack_node **src);
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);
//static void			reverse_rotate(t_stack_node **stack);
void					rra(t_stack_node **stack_a, bool p);
void					rrb(t_stack_node **stack_b, bool p);
void					rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool p);
//static void			rotate(t_stack_node **stack);
void					ra(t_stack_node **stack_a, bool p);
void					rb(t_stack_node **stack_b, bool p);
void					rr(t_stack_node **stack_a, t_stack_node **stack_b, bool p);
//static void			swap(t_stack_node **head);
void					sa(t_stack_node	**stack_a, bool p);
void					sb(t_stack_node **stack_b, bool p);
void					ss(t_stack_node **stack_a, t_stack_node **stack_b, bool p);

// Part of Algo

#endif
