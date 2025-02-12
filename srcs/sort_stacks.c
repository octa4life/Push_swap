/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:40:41 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/04 17:44:22 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack_node **stack_a,t_stack_node **stack_b,t_stack_node *cheapest_n)
{
	while (*stack_b != cheapest_n->target_node
		&& *stack_a != cheapest_n)
		rr(stack_a, stack_b, false);
	current_i (*stack_a);
	current_i (*stack_b);
}

void	rev_rotate_both(t_stack_node **stack_a,t_stack_node **stack_b,t_stack_node *cheapest_n)
{
	while (*stack_b != cheapest_n->target_node
		&& *stack_a != cheapest_n)
		rrr(stack_a, stack_b, false);
	current_i(*stack_a);
	current_i(*stack_b);
}

void	move_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
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

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	before_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

