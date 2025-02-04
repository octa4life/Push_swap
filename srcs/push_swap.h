/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:28:12 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/04 13:14:39 by obellil-         ###   ########.fr       */
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
static long				atol(const char *nptr);
static void				append_node(t_stack_node **stack, int n);
void					stack_init(t_stack_node **a, char **argv);
// Part of Stack Utils
void					ft_check_cheapest(t_stack_node *stack);
void					before_push(t_stack_node **stack,t_stack_node *top_node,char stack_name);
int						stack_len(t_stack_node *stack);
t_stack_node			*find_last(t_stack_node *stack);
bool					stack_sorted(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);

// Part of Commands
static void	push(t_stack_node **dest, t_stack_node **src);
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);
// Part of Algo


#endif
