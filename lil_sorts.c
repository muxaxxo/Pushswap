/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_sorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:55:01 by aalegria          #+#    #+#             */
/*   Updated: 2025/03/11 15:38:50 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lil_sort_sb(t_list *d)
{
	while (d->sib > 0)
	{
		if (d->sb[0] == d->lsp - 1)
		{
			pa(d);
			d->control = 1;
		}
		if (d->sb[0] == d->lsp)
		{
			pa(d);
			d->lsp--;
			if (d->control == 1)
			{
				d->lsp--;
				d->control = 0;
				sa(d->sa);
			}
		}
		else
			rb(d);
	}
}

void	lil_sort3(t_list *d, int i)
{
	while (i >= 0)
	{
		if (d->sa[0] == i)
		{
			pb(d);
			i--;
		}
		else
			ra(d);
	}
	lil_sort_sb(d);
}

void	lil_sort2(t_list *d)
{
	int	i;
	int	j;

	j = 0;
	i = d->lsp;
	while (d->sib < 1)
	{
		if (d->sa[0] == i)
			pb(d);
		else
			ra(d);
	}
}

void	lil_sort(t_list *d)
{
	int	i;
	int	j;

	j = 0;
	i = d->lsp;
	while (d->sib <= (d->argc / 2))
	{
		if (d->sa[0] == i)
		{
			pb(d);
			i--;
		}
		else
			ra(d);
	}
	lil_sort_sb(d);
	lil_sort3(d, i);
}