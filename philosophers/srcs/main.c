/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 01:06:27 by juan-jof          #+#    #+#             */
/*   Updated: 2025/06/28 01:10:19 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	if (parse_arguments(argc, argv, &data) == -1)
		return (1);
	if (init_all(&data, &philos) == -1)
		return (1);
	if (start_simulation(&data, philos) == -1)
	{
		cleanup_all(&data, &philos);
		return (1);
	}
	cleanup_all(&data, &philos);
	return (0);
}
