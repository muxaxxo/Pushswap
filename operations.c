/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:54:12 by aalegria          #+#    #+#             */
/*   Updated: 2024/12/18 13:28:24 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	if (a->size > 1)
		swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (b->size > 1)
		swap(b);
	write(1, "sb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
		push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		push(b, a);
	write(1, "pb\n", 3);
}
