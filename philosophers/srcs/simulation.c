/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 01:29:33 by juan-jof          #+#    #+#             */
/*   Updated: 2025/08/26 01:59:46 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating_action(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal_time = get_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->death_mutex);
	precise_sleep(philo->data->time_to_eat);
}

static int	eat_cycle(t_philo *philo)
{
	take_forks_safe(philo);
	if (simulation_ended(philo->data))
	{
		release_forks(philo);
		return (0);
	}
	print_status(philo, "is eating");
	eating_action(philo);
	release_forks(philo);
	return (1);
}

void	sleeping_action(t_philo *philo)
{
	long long	start_time;
	long long	elapsed;

	start_time = get_time_ms();
	while (!simulation_ended(philo->data))
	{
		elapsed = get_time_ms() - start_time;
		if (elapsed >= philo->data->time_to_sleep)
			break ;
		usleep(100);
	}
}

void	thinking_action(t_philo *philo)
{
	(void)philo;
	precise_sleep(1);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		thinking_action(philo);
	if (philo->data->num_philos == 1)
	{
		take_forks_safe(philo);
		while (!simulation_ended(philo->data))
			usleep(1000);
		release_forks(philo);
		return (NULL);
	}
	while (!simulation_ended(philo->data))
	{
		if (!eat_cycle(philo) || simulation_ended(philo->data))
			break ;
		print_status(philo, "is sleeping");
		sleeping_action(philo);
		if (simulation_ended(philo->data))
			break ;
		print_status(philo, "is thinking");
		thinking_action(philo);
	}
	return (NULL);
}
