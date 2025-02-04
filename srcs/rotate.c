/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:22:19 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/04 14:02:01 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **stack_a, bool p)
{
	rotate(stack_a);
	if (!p)
		ft_printf("ra\n");
}

void	rb(t_stack_node **stack_b, bool p)
{
	rotate(stack_b);
	if (!p)
		ft_print("rb\n");
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, bool p)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!p)
		ft_printf("rr\n");
}
