/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:55:01 by aalegria          #+#    #+#             */
/*   Updated: 2025/03/07 18:33:01 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = get_max_value(a);
	bits = 0;
	while (max)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
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

// void	pre_push_large_numbers(t_stack *a, t_stack *b)
// {
// 	int	i;
// 	int	size;

// 	i = 0;
// 	size = a->size;
// 	while (i < size)
// 	{
// 		if (a->values[0] > 400 || a->values[0] < -400)
// 			pb(a, b);
// 		else
// 			ra(a);
// 		i++;
// 	}
// }

void	optimize_rotations(t_stack *a, t_stack *b)
{
	if (a->size > 1 && b->size > 1 && a->values[0] > a->values[1]
		&& b->values[0] > b->values[1])
	{
		ss(a, b);
	}
	else if (a->size > 1 && a->values[0] > a->values[1])
	{
		sa(a);
	}
	else if (b->size > 1 && b->values[0] > b->values[1])
	{
		sb(b);
	}
}
