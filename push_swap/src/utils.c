/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:57:57 by juan-jof          #+#    #+#             */
/*   Updated: 2025/05/19 19:46:25 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	init_stack(t_stack *stack, char **argv)
{
	int		i;
	long	value;
	t_node	*new;

	stack->top = NULL;
	if (!argv)
		return (1);
	i = 0;
	while (argv[i])
	{
		if (!validate_input(argv[i], stack, &value))
			return (0);
		new = create_node((int)value);
		if (!new)
		{
			free_stack(stack);
			return (0);
		}
		append_node(stack, new);
		i++;
	}
	assign_index(stack);
	return (1);
}

int	stack_size(t_stack *a)
{
	int		count;
	t_node	*current;

	count = 0;
	current = a->top;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	while (stack->top)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
