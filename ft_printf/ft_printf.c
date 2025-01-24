/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:00:12 by aalegria          #+#    #+#             */
/*   Updated: 2024/11/04 12:42:04 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printptr(void *ptr, int *len)
{
	if (ptr == NULL)
		ft_putstr("(nil)", len);
	else
	{
		ft_putstr("0x", len);
		ft_printhex((unsigned long)ptr, 0, len);
	}
}

static void	ft_process_format(const char **format, va_list args, int *len)
{
	if (**format == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (**format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (**format == 'p')
		ft_printptr(va_arg(args, void *), len);
	else if (**format == 'd' || **format == 'i')
		ft_printnbr(va_arg(args, int), len);
	else if (**format == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 10, len);
	else if (**format == 'x' || **format == 'X')
		ft_printhex(va_arg(args, unsigned int), **format == 'X', len);
	else if (**format == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	va_list		args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(++format))
			ft_process_format(&format, args, &len);
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
