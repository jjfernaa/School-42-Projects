/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:28:49 by juan-jof          #+#    #+#             */
/*   Updated: 2025/07/31 02:48:01 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *origin, const char *search, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!origin && !len)
		return (0);
	if (search[0] == '\0' || search == origin)
		return ((char *)origin);
	while (origin[i] != '\0')
	{
		j = 0;
		while (origin[i + j] == search[j] && (i + j) < len)
		{
			if (origin[i + j] == '\0' && search[j] == '\0')
				return ((char *)&origin[i]);
			j++;
		}
		if (search[j] == '\0')
			return ((char *)(origin + i));
		i++;
	}
	return (0);
}
