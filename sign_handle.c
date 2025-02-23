/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:10:15 by aalegria          #+#    #+#             */
/*   Updated: 2025/02/23 11:45:29 by aalegria         ###   ########.fr       */
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
