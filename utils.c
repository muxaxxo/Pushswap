/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:41:59 by aalegria          #+#    #+#             */
/*   Updated: 2024/12/18 13:18:39 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bit(t_stack *a, t_stack *b, int bit)
{
	int	size;
	int	i;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (((a->values[0] >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	while (b->size > 0)
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

void	print_stack_recursive(int *values, int size)
{
	if (size > 0)
	{
		ft_printf("%d ", values[0]);
		print_stack_recursive(values + 1, size - 1);
	}
}

void	print_stack(t_stack *a, t_stack *b)
{
	ft_printf("Stack A: ");
	print_stack_recursive(a->values, a->size);
	ft_printf("\n");
	ft_printf("Stack B: ");
	print_stack_recursive(b->values, b->size);
	ft_printf("\n");
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
