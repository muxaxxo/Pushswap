/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:54:51 by aalegria          #+#    #+#             */
/*   Updated: 2025/03/03 14:26:14 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int	tmp;
	int	i;

	if (a->size > 1)
	{
		tmp = a->values[0];
		i = 0;
		while (i < a->size - 1)
		{
			a->values[i] = a->values[i + 1];
			i++;
		}
		a->values[a->size - 1] = tmp;
		write(1, "rrr\n", 4);
	}
}

void	rb(t_stack *b)
{
	int	tmp;
	int	i;

	if (b->size > 1)
	{
		tmp = b->values[0];
		i = 0;
		while (i < b->size - 1)
		{
			b->values[i] = b->values[i + 1];
			i++;
		}
		b->values[b->size - 1] = tmp;
		write(1, "rrr\n", 4);
	}
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
