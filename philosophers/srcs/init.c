/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:30:09 by juan-jof          #+#    #+#             */
/*   Updated: 2025/06/13 03:18:29 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_forks_mutex(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
	{
		print_error("Memory allocation failed for forks");
		return (-1);
	}
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			print_error("Failed to initialize fork mutex");
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	init_global_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->write_mutex, NULL) != 0)
	{
		print_error("Failed to initialize write mutex");
		return (-1);
	}
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
	{
		print_error("Failed to initialize death mutex");
		pthread_mutex_destroy(&data->write_mutex);
		return (-1);
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	if (init_forks_mutex(data) == -1)
		return (-1);
	if (init_global_mutex(data) == -1)
	{
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		return (-1);
	}
	return (0);
}

int	init_philos(t_philo **philos, t_data *data)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!*philos)
	{
		print_error("Memory allocation failed for philosophers");
		return (-1);
	}
	i = 0;
	while (i < data->num_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].last_meal_time = 0;
		(*philos)[i].data = data;
		(*philos)[i].left_fork = &data->forks[i];
		(*philos)[i].right_fork = &data->forks[(i + 1) % data->num_philos];
		i++;
	}
	return (0);
}

int	init_all(t_data *data, t_philo **philos)
{
	if (init_mutex(data) == -1)
		return (-1);
	if (init_philos(philos, data) == -1)
	{
		cleanup_mutex(data);
		return (-1);
	}
	data->start_time = 0;
	return (0);
}
