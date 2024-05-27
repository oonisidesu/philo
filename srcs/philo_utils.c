/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:00 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/27 17:34:38 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int	check_data_values(int argc, char **argv)
{
	int		i;
	long	value;

	i = 1;
	while (i < argc)
	{
		value = ft_atoll(argv[i]);
		if (value <= 0 || value > INT_MAX)
		{
			print_error("Argument value out of range");
			return (1);
		}
		i++;
	}
	return (0);
}

int	set_data_values(t_data *data, int argc, char **argv)
{
	data->num_philos = ft_atoll(argv[1]);
	data->time_to_die = ft_atoll(argv[2]);
	data->time_to_eat = ft_atoll(argv[3]);
	data->time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
		data->num_must_eat = ft_atoll(argv[5]);
	else
		data->num_must_eat = -1;
	data->all_ate = 0;
	data->dead = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (print_error("Memory allocation failed"));
	return (0);
}

int	initialize_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->meal_mutex, NULL);
	pthread_mutex_init(&data->dead_mutex, NULL);
	return (0);
}

int	create_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->num_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]))
			return (print_error("Thread creation failed"));
		i++;
	}
	return (0);
}

void	join_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->num_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}
