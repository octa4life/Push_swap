/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:29:31 by obellil-          #+#    #+#             */
/*   Updated: 2025/01/31 14:34:16 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static long	atol(const char *nptr)
{
	int		i;
	int		sign;
	long	vartempo;

	i = 0;
	sign = 1;
	vartempo = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
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

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if(!node)
		return;
	node->next = NULL;
	node->nbr = NULL;
	if(!*stack)
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
	long	n;
	long	i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax (argv[i]))
			free_error(a);
		n = atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a);
		if (error_duplicate (*a, (int)n))
			free_error (a);
		append_node (*a, (int)n);
		i++;
	}
}
