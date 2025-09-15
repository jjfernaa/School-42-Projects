/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 02:47:02 by juan-jof          #+#    #+#             */
/*   Updated: 2025/06/28 01:02:42 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	simulation_ended(t_data *data)
{
	int	ended;

	pthread_mutex_lock(&data->death_mutex);
	ended = data->simulation_end;
	pthread_mutex_unlock(&data->death_mutex);
	return (ended);
}

void	print_status(t_philo *philo, char *message)
{
	long long	timestamp;

	if (simulation_ended(philo->data))
		return ;
	timestamp = get_elapsed_time(philo->data->start_time);
	pthread_mutex_lock(&philo->data->write_mutex);
	if (!simulation_ended(philo->data))
	{
		printf("%lld %d %s\n", timestamp, philo->id, message);
	}
	pthread_mutex_unlock(&philo->data->write_mutex);
}

void	print_death(t_philo *philo)
{
	long long	timestamp;

	timestamp = get_elapsed_time(philo->data->start_time);
	pthread_mutex_lock(&philo->data->write_mutex);
	printf("%lld %d died\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->data->write_mutex);
}

void	end_simulation(t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	data->simulation_end = 1;
	pthread_mutex_unlock(&data->death_mutex);
}
