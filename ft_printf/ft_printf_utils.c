/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:54:33 by aalegria          #+#    #+#             */
/*   Updated: 2024/10/17 14:54:39 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		ft_putchar(*str++, len);
}

void	ft_putnbr_base(unsigned long nbr, char *base, int base_len, int *len)
{
	if (nbr >= (unsigned long)base_len)
		ft_putnbr_base(nbr / base_len, base, base_len, len);
	ft_putchar(base[nbr % base_len], len);
}

void	ft_printnbr(long nbr, int *len)
{
	if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr = -nbr;
	}
	ft_putnbr_base(nbr, "0123456789", 10, len);
}

void	ft_printhex(unsigned long nbr, int upper, int *len)
{
	if (upper)
		ft_putnbr_base(nbr, "0123456789ABCDEF", 16, len);
	else
		ft_putnbr_base(nbr, "0123456789abcdef", 16, len);
}
