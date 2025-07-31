/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:36:41 by juan-jof          #+#    #+#             */
/*   Updated: 2025/01/03 23:19:30 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list *args, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = ft_putchar(va_arg(*args, int));
	else if (format == 's')
		count = ft_putstr(va_arg(*args, char *));
	else if (format == 'p')
		count = ft_print_ptr(va_arg(*args, void *));
	else if (format == 'd' || format == 'i')
		count = ft_putnbr(va_arg(*args, int));
	else if (format == 'u')
		count = ft_print_unsigned(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		count = ft_puthex(va_arg(*args, unsigned int), format);
	else if (format == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (0);
	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format(&args, format[i]);
		}
		else if (format[i] != '%')
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
