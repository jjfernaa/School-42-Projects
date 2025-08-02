/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:22:46 by juan-jof          #+#    #+#             */
/*   Updated: 2025/05/19 19:49:46 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	**process_args(int argc, char **argv, int *need_free)
{
	char	**args;

	*need_free = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (NULL);
		*need_free = 1;
		return (args);
	}
	return (argv + 1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		success;
	char	**args;
	int		need_free;

	if (argc < 2)
		return (0);
	args = process_args(argc, argv, &need_free);
	if (!args)
		return (1);
	success = init_stack(&a, args);
	if (need_free)
		free_split(args);
	if (!success)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	init_stack(&b, NULL);
	if (!is_sorted(&a))
		push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
