/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rever_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:54:41 by aalegria          #+#    #+#             */
/*   Updated: 2024/12/18 13:26:51 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	int	tmp;
	int	i;

	if (a->size > 1)
	{
		tmp = a->values[a->size - 1];
		i = a->size - 1;
		while (i > 0)
		{
			a->values[i] = a->values[i - 1];
			i--;
		}
		a->values[0] = tmp;
	}
}

void	rrb(t_stack *b)
{
	int	tmp;
	int	i;

	if (b->size > 1)
	{
		tmp = b->values[b->size - 1];
		i = b->size - 1;
		while (i > 0)
		{
			b->values[i] = b->values[i - 1];
			i--;
		}
		b->values[0] = tmp;
	}
}
