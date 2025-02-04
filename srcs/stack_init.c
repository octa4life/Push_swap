/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:29:31 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/04 17:42:28 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long ft_atol(const char *nptr)
{
	long vartempo;
	int sign;
	int i;

	vartempo = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign -= (nptr[i] == '-') * 2;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		vartempo = vartempo * 10 + (nptr[i++] - '0');
	return (vartempo * sign);
}

static void append_node(t_stack_node **stack)
{
	t_stack_node *node;
	t_stack_node *last_node;

	if (!stack)
		return;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return;
	node->next = NULL;
	node->nbr = 0;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	stack_init(t_stack_node **a, char **argv)
{
	long n;
	long i;

	i = 0;
	while (argv[i])
	{
		if (p_error_syntax(argv[i]))
			p_free_errors(a);
		n = ft_atol(argv[i]);
		append_node(a);
		(*a)->nbr = (int)n;
		i++;
	}
}
