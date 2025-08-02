/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 03:17:45 by juan-jof          #+#    #+#             */
/*   Updated: 2025/05/06 01:00:50 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra_no_print(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	a->top = first->next;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack *a)
{
	ra_no_print(a);
	write(1, "ra\n", 3);
}

void	rb_no_print(t_stack *b)
{
	t_node	*first;
	t_node	*last;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	b->top = first->next;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rb(t_stack *b)
{
	rb_no_print(b);
	write (1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra_no_print(a);
	rb_no_print(b);
	write (1, "rr\n", 3);
}
