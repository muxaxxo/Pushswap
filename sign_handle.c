/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:10:15 by aalegria          #+#    #+#             */
/*   Updated: 2025/02/21 17:15:19 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_positive(t_stack *a, t_stack *b)
{
	int	bits;
	int	i;

	bits = get_max_bits(a);
	i = 0;
	while (i < bits)
	{
		sort_bit(a, b, i);
		i++;
	}
}

void	sort_negative(t_stack *a, t_stack *b)
{
	int	bits;
	int	i;

	bits = get_max_bits(b);
	i = 0;
	while (i < bits)
	{
		sort_bit(b, a, i);
		i++;
	}
}
