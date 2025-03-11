/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:10:15 by aalegria          #+#    #+#             */
/*   Updated: 2025/03/07 17:46:34 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_values(t_stack *a, int shift)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		a->values[i] += shift;
		i++;
	}
}

int	get_min_index(t_stack *stack)
{
	int	i;
	int	min_index;
	int	min_value;

	if (!stack || stack->size == 0)
		return (-1);
	min_index = 0;
	min_value = stack->values[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->values[i] < min_value)
		{
			min_value = stack->values[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}
