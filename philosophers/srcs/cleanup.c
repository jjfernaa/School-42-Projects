/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 01:42:01 by juan-jof          #+#    #+#             */
/*   Updated: 2025/06/13 03:25:43 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	cleanup_forks(t_data *data, int count)
{
	int	i;

	if (!data->forks)
		return ;
	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	data->forks = NULL;
}

void	cleanup_global_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->write_mutex);
	pthread_mutex_destroy(&data->death_mutex);
}

void	cleanup_mutex(t_data *data)
{
	cleanup_forks(data, data->num_philos);
	pthread_mutex_destroy(&data->write_mutex);
	pthread_mutex_destroy(&data->death_mutex);
}

void	cleanup_philos(t_philo **philos)
{
	if (philos && *philos)
	{
		free(*philos);
		*philos = NULL;
	}
}

void	cleanup_all(t_data *data, t_philo **philos)
{
	cleanup_mutex(data);
	cleanup_philos(philos);
}
