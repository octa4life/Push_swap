/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:24:38 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/04 14:18:17 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	p_error_syntax(char *str_n)
{
	if (!str_n || (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9'))))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	str_n++;
	while (*str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
		str_n++;
	}
	return (0);
}

int	p_error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	p_free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	p_free_errors(t_stack_node **a)
{
	p_free_stack(a);
	ft_printf("Error\n");
	exit(1);
}

int	check_quotes(char *s)
{
	while (*s)
		if (*s++ == '"')
			return (1);
	return (0);
}
