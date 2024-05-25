/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:00 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/25 14:40:58 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, int argc, char **argv)
{
	int	i;

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
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->meal_mutex, NULL);
	pthread_mutex_init(&data->dead_mutex, NULL);
	data->start_time = get_time();
	printf("Initialization complete\n");
	return (0);
}

t_philo	*init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!philos)
		return (NULL);
	while (i < data->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].last_meal = get_time();
		philos[i].meals_eaten = 0;
		philos[i].data = data;
		i++;
	}
	printf("Philosophers initialization complete\n");
	return (philos);
}

int	start_simulation(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->num_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]))
			return (print_error("Thread creation failed"));
		i++;
	}
	printf("Simulation started\n");
	check_death(philos);
	i = 0;
	while (i < philos->data->num_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	printf("Simulation ended\n");
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		left_fork;
	int		right_fork;

	philo = (t_philo *)arg;
	data = philo->data;
	left_fork = philo->id - 1;
	right_fork = (philo->id) % data->num_philos;
	while (!data->dead && (data->num_must_eat == -1
			|| philo->meals_eaten < data->num_must_eat))
	{
		if (data->dead)
			return (NULL);
		printf("Philosopher %d is trying to take forks\n", philo->id);
		pthread_mutex_lock(&data->forks[left_fork]);
		print_action(philo, "has taken a fork");
		if (data->num_philos == 1)
		{
			usleep(data->time_to_die * 1000);
			break ;
		}
		pthread_mutex_lock(&data->forks[right_fork]);
		print_action(philo, "has taken a fork");
		print_action(philo, "is eating");
		pthread_mutex_lock(&data->meal_mutex);
		philo->last_meal = get_time();
		pthread_mutex_unlock(&data->meal_mutex);
		sleep_for(data->time_to_eat);
		philo->meals_eaten++;
		pthread_mutex_unlock(&data->forks[left_fork]);
		pthread_mutex_unlock(&data->forks[right_fork]);
		if (data->dead)
			return (NULL);
		print_action(philo, "is sleeping");
		sleep_for(data->time_to_sleep);
		if (data->dead)
			return (NULL);
		print_action(philo, "is thinking");
	}
	printf("Philosopher %d has finished\n", philo->id);
	return (NULL);
}
