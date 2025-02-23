/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:41:59 by aalegria          #+#    #+#             */
/*   Updated: 2025/02/23 11:55:24 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bit(t_stack *a, t_stack *b, int bit)
{
	int	size;
	int	i;
	int	mtb;

	size = a->size;
	i = 0;
	mtb = 0;
	while (i < size)
	{
		if (((a->values[0] >> bit) & 1) == 0)
		{
			pb(a, b);
			mtb++;
		}
		else
			ra(a);
		i++;
	}
	if (mtb > 0)
	{
		while (b->size > 0)
			pa(a, b);
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
