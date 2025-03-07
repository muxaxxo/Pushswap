/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rare_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:04:14 by aalegria          #+#    #+#             */
/*   Updated: 2025/03/06 13:42:04 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	if (a->values[0] > a->values[1] && a->values[1] < a->values[2]
		&& a->values[0] < a->values[2])
		sa(a);
	else if (a->values[0] > a->values[1] && a->values[1] > a->values[2])
	{
		sa(a);
		rra(a);
	}
	else if (a->values[0] > a->values[1] && a->values[1] < a->values[2])
		ra(a);
	else if (a->values[0] < a->values[1] && a->values[1] > a->values[2]
		&& a->values[0] < a->values[2])
	{
		sa(a);
		ra(a);
	}
	else if (a->values[0] < a->values[1] && a->values[1] > a->values[2])
		rra(a);
}

void sort_five(t_stack *a, t_stack *b)
{
    while (a->size > 3)
    {
        int min = get_min_value(a);
        int index = find_index(a, min);

        if (index <= a->size / 2)
            while (a->values[0] != min)
                ra(a);
        else
            while (a->values[0] != min)
                rra(a);
        
        pb(a, b);
		optimize_rotations(a, b); 
    }
    sort_three(a);
    pa(a, b);
    pa(a, b);
}


int	get_min_value(t_stack *stack)
{
	int	min;
	int	i;

	min = stack->values[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->values[i] < min)
			min = stack->values[i];
		i++;
	}
	return (min);
}

int	get_second_min_value(t_stack *stack)
{
	int	min;
	int	second_min;
	int	i;

	min = get_min_value(stack);
	second_min = __INT_MAX__;
	i = 0;
	while (i < stack->size)
	{
		if (stack->values[i] > min && stack->values[i] < second_min)
			second_min = stack->values[i];
		i++;
	}
	return (second_min);
}
