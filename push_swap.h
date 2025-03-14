/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:54:25 by aalegria          #+#    #+#             */
/*   Updated: 2025/03/07 17:48:37 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*values;
	int	size;
}	t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

int		parse_args(int argc, char **argv, t_stack *a);
void	handle_error(void);

void	sort_bit(t_stack *a, t_stack *b, int bit);
void	free_stack(t_stack *stack);
void	swap(t_stack *stack);
void	push(t_stack *dst, t_stack *src);
void	cleanup_and_exit(t_stack *a, t_stack *b, int code);
int		init_stacks(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack);
void	sort_small_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
int		get_min_value(t_stack *stack);
int		get_second_min_value(t_stack *stack);
int		get_max_bits(t_stack *a);
void	push_swap(t_stack *a, t_stack *b);
void	normalize_values(t_stack *a, int shift);
void	rrr(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
int		get_max_value(t_stack *stack);
void	optimize_rotations(t_stack *a, t_stack *b);
int		find_index(t_stack *stack, int value);
//void	pre_push_large_numbers(t_stack *a, t_stack *b);
int		get_min_index(t_stack *stack);
#endif
