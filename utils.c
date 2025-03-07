/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:41:59 by aalegria          #+#    #+#             */
/*   Updated: 2025/03/07 15:25:07 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_and_push(t_stack *a, t_stack *b, int bit, int *pushed)
{
	int	size;
	int	rotated;

	size = a->size;
	rotated = 0;
	while (size--)
	{
		if (((a->values[0] >> bit) & 1) == 0)
		{
			pb(a, b);
			(*pushed)++;
		}
		else if (rotated > 0)
		{
			rra(a);
			rotated--;
		}
		else
		{
			ra(a);
			rotated++;
		}
	}
}

void	sort_bit(t_stack *a, t_stack *b, int bit)
{
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
	rotate_and_push(a, b, bit, &pushed);
	optimize_rotations(a, b);
	while (a->size > 0 && ((a->values[0] >> bit) & 1) == 1)
	{
		ra(a);
		rotated++;
	}
	while (rotated > 0)
	{
		rra(a);
		rotated--;
	}
	while (pushed > 0)
	{
		pa(a, b);
		pushed--;
	}
}


void	free_stack(t_stack *stack)
{
	if (stack->values)
	{
		free(stack->values);
		stack->values = NULL;
	}
	stack->size = 0;
}

void	sort_small_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->values[0] > a->values[1])
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
}

int	get_max_value(t_stack *stack)
{
	int	max;
	int	i;

	max = stack->values[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->values[i] > max)
			max = stack->values[i];
		i++;
	}
	return (max);
}
