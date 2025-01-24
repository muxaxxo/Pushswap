/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:41:03 by aalegria          #+#    #+#             */
/*   Updated: 2024/12/18 13:18:28 by aalegria         ###   ########.fr       */
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

void	cleanup_and_exit(t_stack *a, t_stack *b, int code)
{
	free_stack(a);
	free_stack(b);
	exit(code);
}
