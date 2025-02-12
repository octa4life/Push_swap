/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:19:41 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/04 14:28:42 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b, bool p)
{
	push(stack_a, stack_b);
	if (!p)
		ft_printf("pa\n");
}


void	pb(t_stack_node **stack_b, t_stack_node **stack_a, bool p)
{
	push(stack_b, stack_a);
	if (!p)
		ft_printf("pb\n");
}
