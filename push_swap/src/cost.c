/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:41:06 by juan-jof          #+#    #+#             */
/*   Updated: 2025/05/06 17:20:26 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	assign_cost(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		size_a;
	int		size_b;

	current = b->top;
	size_a = stack_size(a);
	size_b = stack_size(b);
	while (current)
	{
		if (current->pos < size_b / 2)
			current->cost_b = current->pos;
		else
			current->cost_b = (current->pos - size_b);
		if (current->target_pos < size_a / 2)
			current->cost_a = current->target_pos;
		else
			current->cost_a = (current->target_pos - size_a);
		current = current->next;
	}
}

t_node	*low_cost_node(t_stack *b)
{
	t_node	*current;
	t_node	*lowest;
	int		lowest_cost;
	int		total_cost;

	if (!b || !b->top)
		return (NULL);
	current = b->top;
	lowest = current;
	lowest_cost = ft_abs(current->cost_a) + ft_abs(current->cost_b);
	while (current)
	{
		total_cost = ft_abs(current->cost_a) + ft_abs(current->cost_b);
		if (total_cost < lowest_cost)
		{
			lowest_cost = total_cost;
			lowest = current;
		}
		current = current->next;
	}
	return (lowest);
}
