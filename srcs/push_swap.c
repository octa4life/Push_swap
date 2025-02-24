/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:17:39 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/04 17:43:08 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_args(t_stack_node **a, int argc, char **argv)
{
	char	**split_args;

	if (argc == 2)
	{
		split_args = my_split(argv[1], ' ');
		if (!split_args)
			return (1);
		init_stack_a(a, split_args);
		free_split(split_args);
	}
	else
		init_stack_a(a, argv + 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (parse_args(&a, argc, argv))
		return (1);
	if (!stack_sorted(a) && stack_len(a) == 2)
		sa(&a, false);
	else if (!stack_sorted(a) && stack_len(a) == 3)
		sort_three(&a);
	else if (!stack_sorted(a))
		sort_stacks(&a, &b);
	p_free_stack(&a);
	return (0);
}
