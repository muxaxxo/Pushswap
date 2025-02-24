/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushandswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:14:10 by aalegria          #+#    #+#             */
/*   Updated: 2025/02/24 15:39:35 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->values[0];
	stack->values[0] = stack->values[1];
	stack->values[1] = tmp;
}

void	push(t_stack *dst, t_stack *src)
{
	int	i;

	i = dst->size;
	while (i > 0)
	{
		dst->values[i] = dst->values[i - 1];
		i--;
	}
	dst->values[0] = src->values[0];
	i = 0;
	while (i < src->size - 1)
	{
		src->values[i] = src->values[i + 1];
		i++;
	}
	dst->size++;
	src->size--;
}

int	init_stacks(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (argc < 2)
		return (0);
	stack_a->size = argc - 1;
	stack_a->values = malloc(sizeof(int) * stack_a->size);
	if (!stack_a->values)
		handle_error();
	stack_b->size = 0;
	stack_b->values = malloc(sizeof(int) * stack_a->size);
	if (!stack_b->values)
		handle_error();
	i = 0;
	while (i < stack_a->size)
	{
		stack_a->values[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (1);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	bits;
	int	i;
	int	min_value;

	if (is_sorted(a))
		return ;
	if (a->size <= 5)
	{
		sort_small_stack(a, b);
		return ;
	}
	min_value = get_min_value(a);
	if (min_value < 0)
		normalize_values(a, -min_value);
	bits = get_max_bits(a);
	i = 0;
	while (i < bits)
	{
		sort_bit(a, b, i);
		i++;
	}
	if (min_value < 0)
		normalize_values(a, min_value);
}
