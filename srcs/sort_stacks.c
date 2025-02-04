/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:40:41 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/04 14:02:39 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	 mov_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest_n;

	cheapest_n = ft_check_cheapest;
	if(cheapest_n-> above_median && cheapest_n ->target_node->above_median)
		rotate_both(stack_a,stack_b);
	else if(!(cheapest_n->above_median) && !(cheapest_n->target_node->above_median));
		rev_rotate_both(stack_a,stack_b,cheapest_n);
	before_push(stack_a,cheapest_n,'a');
	before_push(stack_b,cheapest_n,'a');
	pb(stack_a,stack_b,false);
}
static void	move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	before_push(stack_a, (*stack_b)->target_node,'a');
	pa(stack_a, stack_b, false);
}
static void	min_ontop(t_stack_node **stack_a, t_stack_node **stack_b)
{
	while ((*stack_a)->nbr !=find_min(*stack_a)->nbr)
	{
		if(find_min(*stack_a)-> above_median)
			ra(stack_a,false);
		else
			rra(stack_a,false);
	}
}
void	sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && ! stack_sorted (*stack_a))
		pb(stack_b, stack_a, false);
	if (len_a-- > 3 && ! stack_sorted (*stack_a))
		pb(stack_b, stack_a, false);
	while (len_a-- > 3 && !stack_sorted (*stack_a))
	{
		init_n_a(*stack_a,*stack_b);
		move_a_to_b (stack_a,stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_n_b(*stack_a,*stack_b);
		move_b_to_a (stack_a,stack_b);
	}
	current_i(*stack_a);
	min_on_top(stack_a);
}
