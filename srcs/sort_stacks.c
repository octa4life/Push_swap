/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:40:41 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/04 16:55:45 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **stack_a,t_stack_node **stack_b,t_stack_node *cheapest_n)
{
	while (*stack_b != cheapest_n->target_node
		&& *stack_a != cheapest_n)
		rr(stack_a, stack_b, false);
	current_i (*stack_a);
	current_i (*stack_b);
}

static void	rev_rotate_both(t_stack_node **stack_a,t_stack_node **stack_b,t_stack_node *cheapest_n)
{
	while (*stack_b != cheapest_n->target_node
		&& *stack_a != cheapest_n)
		rrr(stack_a, stack_b, false);
	current_i(*stack_a);
	current_i(*stack_b);
}

static void	move_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest_n;

	cheapest_n = ft_check_cheapest(*stack_a);
	if (cheapest_n->above_median
		&& cheapest_n->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_n);
	else if (!(cheapest_n->above_median)
		&& !(cheapest_n->target_node->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest_n);
	before_push(stack_a, cheapest_n, 'a');
	before_push(stack_b, cheapest_n->target_node, 'b');
	pb(stack_b, stack_a, false);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	before_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_i(*a);
	min_on_top(a);
}
