/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:53:58 by aalegria          #+#    #+#             */
/*   Updated: 2024/12/18 13:27:59 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_args(int argc, char **argv, t_stack *a)
{
	int	i;
	int	j;

	a->values = malloc(sizeof(int) * (argc - 1));
	if (!a->values)
		handle_error();
	i = 1;
	while (i < argc)
	{
		a->values[i - 1] = ft_atoi(argv[i]);
		if (argv[i][0] == '\0' || (ft_atoi(argv[i]) == 0 && argv[i][0] != '0'))
			handle_error();
		j = i + 1;
		while (j < argc)
		{
			if (a->values[i - 1] == ft_atoi(argv[j]))
				handle_error();
			j++;
		}
		i++;
	}
	a->size = argc - 1;
	return (1);
}

void	handle_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
