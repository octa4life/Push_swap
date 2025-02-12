/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:22:10 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/04 14:30:10 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **stack_a, bool p)
{
	reverse_rotate(stack_a);
	if (!p)
		printf("rra\n");
}

void	rrb(t_stack_node **stack_b, bool p)
{
	reverse_rotate(stack_b);
	if (!p)
		printf("rrb\n");
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool p)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (!p)
		printf("rrr\n");
}
