/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:55:01 by aalegria          #+#    #+#             */
/*   Updated: 2024/12/18 13:27:49 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;
	int	i;

	max = a->values[0];
	i = 1;
	while (i < a->size)
	{
		if (a->values[i] > max)
			max = a->values[i];
		i++;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	bits;
	int	i;

	if (a->size <= 5)
	{
		sort_small_stack(a, b);
		return ;
	}
	bits = get_max_bits(a);
	i = 0;
	while (i < bits)
	{
		sort_bit(a, b, i);
		i++;
	}
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->values[i] > stack->values[i + 1])
			return (0);
		i++;
	}
	return (1);
}
