/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 04:21:59 by juan-jof          #+#    #+#             */
/*   Updated: 2025/08/26 00:48:57 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	should_die(t_philo *philo)
{
	long long	time_since_meal;
	long long	current_time;

	current_time = get_time_ms();
	if (current_time == -1)
		return (1);
	pthread_mutex_lock(&philo->data->death_mutex);
	time_since_meal = current_time - philo->last_meal_time;
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (time_since_meal >= philo->data->time_to_die);
}

int	all_have_eaten_enough(t_philo *philos, t_data *data)
{
	int	i;
	int	satisfied_count;

	if (data->must_eat_count == -1)
		return (0);
	satisfied_count = 0;
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (philos[i].meals_eaten >= data->must_eat_count)
			satisfied_count++;
		pthread_mutex_unlock(&data->death_mutex);
		i++;
	}
	return (satisfied_count == data->num_philos);
}

int	find_dead_philosopher(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (should_die(&philos[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philos;
	t_data	*data;
	int		dead_philo;

	data = ((t_philo *)arg)->data;
	philos = ((t_philo *)arg);
	while (!simulation_ended(data))
	{
		dead_philo = find_dead_philosopher(philos, data);
		if (dead_philo != -1)
		{
			print_death(&philos[dead_philo]);
			end_simulation(data);
			return (NULL);
		}
		if (all_have_eaten_enough(philos, data))
		{
			end_simulation(data);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

int	start_simulation(t_data *data, t_philo *philos)
{
	pthread_t	monitor_thread;

	if (set_initial_times(philos, data) == -1)
		return (-1);
	if (pthread_create(&monitor_thread, NULL, monitor_routine, philos) != 0)
	{
		print_error("failed to create monitor thread");
		return (-1);
	}
	if (create_philosopher_threads(data, philos) == -1)
		return (-1);
	wait_all_threads(data, philos, monitor_thread);
	return (0);
}
