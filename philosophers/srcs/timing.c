/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 02:36:31 by juan-jof          #+#    #+#             */
/*   Updated: 2025/08/26 01:59:57 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		print_error("failed to get time");
		return (-1);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long	get_elapsed_time(long long start_time)
{
	return (get_time_ms() - start_time);
}

void	precise_sleep(long long sleep_time)
{
	long long	start;
	long long	elapsed;

	start = get_time_ms();
	while (1)
	{
		elapsed = get_time_ms() - start;
		if (elapsed >= sleep_time)
			break ;
		if (sleep_time - elapsed > 1000)
			usleep(500);
		else
			usleep(50);
	}
}

int	set_initial_times(t_philo *philos, t_data *data)
{
	int	i;

	data->start_time = get_time_ms();
	if (data->start_time == -1)
		return (-1);
	i = 0;
	while (i < data->num_philos)
	{
		philos[i].last_meal_time = data->start_time;
		i++;
	}
	return (0);
}
