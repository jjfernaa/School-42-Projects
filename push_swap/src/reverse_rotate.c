/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 03:17:49 by juan-jof          #+#    #+#             */
/*   Updated: 2025/05/06 01:01:09 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra_no_print(t_stack *a)
{
	t_node	*last;
	t_node	*penultimate;

	if (!a || !a->top || !a->top->next)
		return ;
	penultimate = a->top;
	while (penultimate->next && penultimate->next->next)
		penultimate = penultimate->next;
	last = penultimate->next;
	penultimate->next = NULL;
	last->next = a->top;
	a->top = last;
}

void	rra(t_stack *a)
{
	rra_no_print(a);
	write (1, "rra\n", 4);
}

void	rrb_no_print(t_stack *b)
{
	t_node	*last;
	t_node	*penultimate;

	if (!b || !b->top || !b->top->next)
		return ;
	penultimate = b->top;
	while (penultimate->next && penultimate->next->next)
		penultimate = penultimate->next;
	last = penultimate->next;
	penultimate->next = NULL;
	last->next = b->top;
	b->top = last;
}

void	rrb(t_stack *b)
{
	rrb_no_print(b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra_no_print(a);
	rrb_no_print(b);
	write (1, "rrr\n", 4);
}
