/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:33:41 by juan-jof          #+#    #+#             */
/*   Updated: 2025/05/07 04:02:38 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int		size;

	size = stack_size(a);
	if (size == 2 && a->top->value > a->top->next->value)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		sort_large(a, b);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	pos;

	while (stack_size(a) > 3)
	{
		pos = find_lowest_pos(a);
		if (pos == 0)
			pb(a, b);
		else if (pos <= stack_size(a) / 2)
		{
			while (pos-- > 0)
				ra (a);
			pb(a, b);
		}
		else
		{
			pos = stack_size(a) - pos;
			while (pos-- > 0)
				rra(a);
			pb(a, b);
		}
	}
	sort_three(a);
	while (stack_size(b) > 0)
		pa(a, b);
}

void	sort_large(t_stack *a, t_stack *b)
{
	t_node	*best_node;

	while (stack_size(a) > 3)
		pb(a, b);
	sort_three(a);
	while (stack_size (b) > 0)
	{
		assign_position(a);
		assign_position(b);
		assign_target_position(a, b);
		assign_cost(a, b);
		best_node = low_cost_node(b);
		execute_move(a, b, best_node);
	}
	if (!is_sorted(a))
		final_rotate(a);
}

void	final_rotate(t_stack *a)
{
	int	pos;
	int	size;

	pos = find_lowest_pos(a);
	size = stack_size(a);
	if (pos <= size / 2)
	{
		while (pos--)
			ra(a);
	}
	else
	{
		while (pos++ < size)
			rra(a);
	}
}
