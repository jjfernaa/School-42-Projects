/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:53:17 by juan-jof          #+#    #+#             */
/*   Updated: 2025/01/03 23:11:11 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int num)
{
	int		len;
	char	digit;

	len = 0;
	if (num >= 10)
	{
		len += ft_print_unsigned(num / 10);
		len += ft_print_unsigned(num % 10);
	}
	else
	{
		digit = num + '0';
		len += write(1, &digit, 1);
	}
	return (len);
}
