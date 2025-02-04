/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:22:29 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/04 13:45:25 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node	**stack_a, bool p)
{
	swap(stack_a);
	if (!p)
		printf("sa\n");
}

void	sb(t_stack_node **stack_b, bool p)
{
	swap(stack_b);
	if (!p)
		printf("sb\n");
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b, bool p)
{
	swap(stack_a);
	swap(stack_b);
	if (!p)
		printf("ss\n");
}

