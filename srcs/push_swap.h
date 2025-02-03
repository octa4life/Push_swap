/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:28:12 by obellil-          #+#    #+#             */
/*   Updated: 2025/01/30 17:26:27 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack_node
{
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
}	t_stack_node;

// Part of Errors

// Part Stack initiation

// Part of Nodes initiation

// Part of Stack Utils

// Part of Commands

// Part of Algo
#endif
