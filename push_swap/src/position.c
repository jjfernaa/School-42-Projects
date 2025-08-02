/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:39:27 by juan-jof          #+#    #+#             */
/*   Updated: 2025/05/17 15:03:02 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	assign_position(t_stack *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		current->pos = i;
		current = current->next;
		i++;
	}
}

int	find_pos_above_index(t_stack *a, int b_index, int *found)
{
	t_node	*current;
	int		min_index;
	int		pos;
	int		result_pos;

	current = a->top;
	min_index = INT_MAX;
	pos = 0;
	result_pos = 0;
	*found = 0;
	while (current)
	{
		if (current->index > b_index && current->index < min_index)
		{
			min_index = current->index;
			result_pos = pos;
			*found = 1;
		}
		current = current->next;
		pos++;
	}
	return (result_pos);
}

int	find_pos_min_index(t_stack *a)
{
	t_node	*current;
	int		min_index;
	int		pos;
	int		result_pos;

	current = a->top;
	min_index = INT_MAX;
	pos = 0;
	result_pos = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			result_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (result_pos);
}

int	get_target_pos(t_stack *a, int b_index)
{
	int	found;
	int	pos;

	pos = find_pos_above_index(a, b_index, &found);
	if (found)
		return (pos);
	pos = find_pos_min_index(a);
	return (pos);
}

void	assign_target_position(t_stack *a, t_stack *b)
{
	t_node	*current_b;
	int		target_pos;

	if (!a || !b)
		return ;
	current_b = b->top;
	while (current_b)
	{
		target_pos = get_target_pos(a, current_b->index);
		current_b->target_pos = target_pos;
		current_b = current_b->next;
	}
}
