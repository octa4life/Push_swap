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

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheap_n)
{
	while (*b != cheap_n->target_node
		&& *a != cheap_n)
		rr(a, b, false);
	current_i (*a);
	current_i (*b);
}

void	rev_rotate_both(t_stack_node **a,
		t_stack_node **b, t_stack_node *cheap_n)
{
	while (*b != cheap_n->target_node
		&& *a != cheap_n)
		rrr(a, b, false);
	current_i(*a);
	current_i(*b);
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap_n;

	cheap_n = ft_check_cheapest(*a);
	if (cheap_n->above_median
		&& cheap_n->target_node->above_median)
		rotate_both(a, b, cheap_n);
	else if (!(cheap_n->above_median)
		&& !(cheap_n->target_node->above_median))
		rev_rotate_both(a, b, cheap_n);
	before_push(a, cheap_n, 'a');
	before_push(b, cheap_n->target_node, 'b');
	pb(b, a, false);
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

