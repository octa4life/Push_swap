/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:40:41 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/03 13:19:42 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if(len_a-- > 3 && ! stack_sorted (*stack_a))
		pb(stack_b, stack_a, false);
	if(len_a-- > 3 && ! stack_sorted (*stack_a))
		pb(stack_b, stack_a, false);
	while(len_a-- > 3 && !stack_sorted (*stack_a))
	{
		init_n_a(*stack_a,*stack_b);
		move_a_to_b(stack_a,stack_b);
	}
	sort_three(stack_a);
	while(*stack_b)
	{
		init_n_b(*stack_a,*stack_b);
		move_b_to_a(stack_a,stack_b);
	}
	current_i(*stack_a);
	min_on_top(stack_a);
}
