/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:43:41 by juan-jof          #+#    #+#             */
/*   Updated: 2025/06/06 02:53:15 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_valid_number(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (0);
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_data *data)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		print_error("Incorrect number of arguments");
		return (-1);
	}
	i = 0;
	while (++i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			print_error("All arguments must be positive numbers");
			return (-1);
		}
	}
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat_count = ft_atoi(argv[5]);
	else
		data->must_eat_count = -1;
	return (validate_range(data));
}

int	validate_range(t_data *data)
{
	if (data->num_philos < 1 || data->num_philos > 200)
	{
		print_error("The number of philosophers must be between 1 and 200.");
		return (-1);
	}
	if (validate_times(data) == -1)
		return (-1);
	if (data->must_eat_count != -1 && data->must_eat_count < 1)
	{
		print_error("must eat must be greater than 0");
		return (-1);
	}
	data->simulation_end = 0;
	data->start_time = 0;
	return (0);
}

int	validate_times(t_data *data)
{
	if (data->time_to_die < 1)
	{
		print_error("time to die must be greater than 0");
		return (-1);
	}
	if (data->time_to_eat < 1)
	{
		print_error("time to eat must be greater than 0");
		return (-1);
	}
	if (data->time_to_sleep < 1)
	{
		print_error("time to sleep must be greater than 0");
		return (-1);
	}
	return (0);
}
