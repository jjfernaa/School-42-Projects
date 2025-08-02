/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:18:17 by juan-jof          #+#    #+#             */
/*   Updated: 2025/05/06 21:06:22 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	append_node(t_stack *stack, t_node *new)
{
	t_node	*current;

	if (!stack->top)
		stack->top = new;
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

int	find_lowest_pos(t_stack *a)
{
	t_node	*current;
	int		lowest;
	int		pos;
	int		i;

	current = a->top;
	lowest = current->index;
	pos = 0;
	i = 0;
	while (current)
	{
		if (current->index < lowest)
		{
			lowest = current->index;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}
