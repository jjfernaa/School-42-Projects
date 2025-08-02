/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 00:30:19 by juan-jof          #+#    #+#             */
/*   Updated: 2025/05/19 19:52:19 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
int		init_stack(t_stack *stack, char **argv);
int		ft_abs(int n);
int		stack_size(t_stack *a);
void	assign_index(t_stack *a);
void	print_stack(t_stack *stack, char name);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *a);
void	push_swap(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);
void	final_rotate(t_stack *a);
void	assign_position(t_stack *stack);
void	assign_target_position(t_stack *a, t_stack *b);
int		get_target_pos(t_stack *a, int b_index);
int		find_pos_above_index(t_stack *a, int b_index, int *found);
int		find_pos_min_index(t_stack *a);
int		find_lowest_pos(t_stack *a);
void	assign_cost(t_stack *a, t_stack *b);
t_node	*low_cost_node(t_stack *b);
void	two_rotate(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
void	rotate_a(t_stack *a, int cost);
void	rotate_b(t_stack *b, int cost);
void	execute_move(t_stack *a, t_stack *b, t_node *node);
int		is_valid_number(char *str);
int		has_duplicates(t_stack *stack, int value);
int		validate_input(char *arg, t_stack *stack, long *value);
t_node	*create_node(int value);
void	append_node(t_stack *stack, t_node *new);
char	**ft_split(char const *s, char c);
void	free_split(char **split);

#endif
