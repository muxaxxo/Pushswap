/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:41:59 by aalegria          #+#    #+#             */
/*   Updated: 2025/02/24 15:52:32 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bit(t_stack *a, t_stack *b, int bit)
{
	int	size;
	int	pushed;
	int	rotated;

	size = a->size;
	pushed = 0;
	rotated = 0;
	while (size--)
	{
		if (((a->values[0] >> bit) & 1) == 0)
		{
			pb(a, b);
			pushed++;
		}
		else
		{
			ra(a);
			rotated++;
		}
	}
	while (rotated--)
		rra(a);
	while (pushed--)
		pa(a, b);
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
