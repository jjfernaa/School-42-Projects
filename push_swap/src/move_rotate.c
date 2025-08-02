/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:29:59 by juan-jof          #+#    #+#             */
/*   Updated: 2025/05/07 01:22:00 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	two_rotate(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		*cost_a -= 1;
		*cost_b -= 1;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		*cost_a += 1;
		*cost_b += 1;
	}
}

void	rotate_a(t_stack *a, int cost)
{
	while (cost > 0)
	{
		ra(a);
		cost--;
	}
	while (cost < 0)
	{
		rra(a);
		cost++;
	}
}

void	rotate_b(t_stack *b, int cost)
{
	while (cost > 0)
	{
		rb(b);
		cost--;
	}
	while (cost < 0)
	{
		rrb(b);
		cost++;
	}
}

void	execute_move(t_stack *a, t_stack *b, t_node *node)
{
	int	cost_a;
	int	cost_b;

	cost_a = node->cost_a;
	cost_b = node->cost_b;
	two_rotate(a, b, &cost_a, &cost_b);
	rotate_a(a, cost_a);
	rotate_b(b, cost_b);
	pa(a, b);
}
