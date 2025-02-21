/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushandswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:14:10 by aalegria          #+#    #+#             */
/*   Updated: 2025/02/21 14:51:00 by aalegria         ###   ########.fr       */
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

void	separate_negatives(t_stack *a, t_stack *b)
{
	int	size;
	int	i;

	i = 0;
	size = a->size;
	while (i < size)
	{
		if (a->values[0] < 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}
