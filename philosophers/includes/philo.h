/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 03:06:53 by juan-jof          #+#    #+#             */
/*   Updated: 2025/06/28 01:14:28 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

// principal struct
typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	long long		start_time;
	int				simulation_end;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	death_mutex;
}	t_data;

// Philo struct
typedef struct s_philo
{
	int				id;
	long long		last_meal_time;
	int				meals_eaten;
	pthread_t		thread;
	t_data			*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

// Funtion parsing
int			parse_arguments(int argc, char **argv, t_data *data);
int			validate_range(t_data *data);
int			validate_times(t_data *data);
int			is_valid_number(char *str);
void		print_error(char *message);
int			ft_atoi(const char *str);

// Init functions
int			init_forks_mutex(t_data *data);
int			init_global_mutex(t_data *data);
int			init_mutex(t_data *data);
int			init_philos(t_philo **philos, t_data *data);
int			init_all(t_data *data, t_philo **philos);

// Cleanup funtions
void		cleanup_forks(t_data *data, int count);
void		cleanup_global_mutex(t_data *data);
void		cleanup_mutex(t_data *data);
void		cleanup_philos(t_philo **philos);
void		cleanup_all(t_data *data, t_philo **philos);

// Timing functions
long long	get_time_ms(void);
long long	get_elapsed_time(long long start_time);
void		precise_sleep(long long sleep_time);
int			set_initial_times(t_philo *philos, t_data *data);

// Logging functions
int			simulation_ended(t_data *data);
void		print_status(t_philo *philo, char *message);
void		print_death(t_philo *philo);
void		end_simulation(t_data *data);

// Forks management functions
void		take_forks_safe(t_philo *philo);
void		release_forks(t_philo *philo);

// Simulation functions
void		eating_action(t_philo *philo);
void		sleeping_action(t_philo *philo);
void		thinking_action(t_philo *philo);
void		*philosopher_routine(void *arg);

// Thread management
int			wait_all_threads(t_data *data, t_philo *philos,
				pthread_t monitor_thread);
int			create_philosopher_threads(t_data *data, t_philo *philos);

//Monitoring functions
int			should_die(t_philo *philo);
int			all_have_eaten_enough(t_philo *philos, t_data *data);
int			find_dead_philosopher(t_philo *philos, t_data *data);
void		*monitor_routine(void *arg);
int			start_simulation(t_data *data, t_philo *philos);

#endif