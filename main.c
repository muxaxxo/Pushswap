/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:41:03 by aalegria          #+#    #+#             */
/*   Updated: 2025/02/21 17:17:23 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	if (!init_stacks(argc, argv, &stack_a, &stack_b))
		return (1);
	if (is_sorted(&stack_a))
		cleanup_and_exit(&stack_a, &stack_b, 0);
	push_swap(&stack_a, &stack_b);
	print_stack(&stack_a, &stack_b);
	cleanup_and_exit(&stack_a, &stack_b, 0);
}
