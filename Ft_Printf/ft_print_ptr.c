/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:01:34 by juan-jof          #+#    #+#             */
/*   Updated: 2025/01/13 18:58:48 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	char			*hex;
	int				len;
	unsigned long	add;

	if (ptr == 0)
		return (write (1, "(nil)", 5));
	hex = "0123456789abcdef";
	len = write (1, "0x", 2);
	add = (unsigned long)ptr;
	if (ptr == NULL)
		return (len + write (1, "0", 1));
	if (add >= 16)
		len += ft_print_hex(add / 16, hex);
	len += write(1, &hex[add % 16], 1);
	return (len);
}

int	ft_print_hex(unsigned long num, char *hex)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_print_hex(num / 16, hex);
	len += write(1, &hex[num % 16], 1);
	return (len);
}
