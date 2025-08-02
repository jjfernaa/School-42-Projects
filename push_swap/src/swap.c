/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:46:21 by juan-jof          #+#    #+#             */
/*   Updated: 2025/05/06 01:00:22 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sa_no_print(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
}

void	sa(t_stack *a)
{
	sa_no_print(a);
	write(1, "sa\n", 3);
}

static void	sb_no_print(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
}

void	sb(t_stack *b)
{
	sb_no_print(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa_no_print(a);
	sb_no_print(b);
	write (1, "ss\n", 3);
}
