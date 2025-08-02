/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:13:39 by juan-jof          #+#    #+#             */
/*   Updated: 2025/05/01 23:02:03 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "limits.h"

void	assign_index(t_stack *a)
{
	t_node	*current;
	t_node	*min_node;
	int		index;
	int		min_value;

	index = 0;
	while (index < stack_size(a))
	{
		current = a->top;
		min_value = INT_MAX;
		min_node = NULL;
		while (current)
		{
			if (current->index == -1 && current->value < min_value)
			{
				min_value = current->value;
				min_node = current;
			}
			current = current->next;
		}
		if (min_node)
			min_node->index = index++;
	}
}
