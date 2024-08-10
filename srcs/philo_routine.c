/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:00 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/08/10 18:29:58 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	run_philo_routine(philo);
	return (NULL);
}

void	run_philo_routine(t_philo *philo)
{
	t_data	*data;
	int		left_fork;
	int		right_fork;

	data = philo->data;
	left_fork = philo->id - 1;
	right_fork = philo->id % data->num_philos;
	while (!data->dead && (data->num_must_eat == -1
			|| philo->meals_eaten < data->num_must_eat))
	{
		if (philo->id % 2 == 0)
			usleep(100);
		if (take_forks(philo, left_fork, right_fork) == 1)
			return ;
		if (perform_eating(philo, data) == 1)
			return ;
		if (put_down_forks(philo, left_fork, right_fork) == 1)
			return ;
		if (perform_sleeping(philo, data) == 1)
			return ;
		print_action(philo, "is thinking");
	}
}

int	handle_single_philo(t_philo *philo, t_data *data, int first_fork)
{
	if (data->num_philos == 1)
	{
		usleep(data->time_to_die * 1000);
		print_action(philo, "died");
		pthread_mutex_unlock(&data->forks[first_fork]);
		return (1);
	}
	return (0);
}

int	take_fork_pair(t_philo *philo, int first_fork, int second_fork)
{
	t_data	*data;

	data = philo->data;
	if (data->dead)
		return (1);
	pthread_mutex_lock(&data->forks[first_fork]);
	print_action(philo, "has taken a fork");
	if (handle_single_philo(philo, data, first_fork))
		return (1);
	if (data->dead)
	{
		pthread_mutex_unlock(&data->forks[first_fork]);
		return (1);
	}
	pthread_mutex_lock(&data->forks[second_fork]);
	print_action(philo, "has taken a fork");
	if (data->dead)
	{
		pthread_mutex_unlock(&data->forks[second_fork]);
		pthread_mutex_unlock(&data->forks[first_fork]);
		return (1);
	}
	return (0);
}

int	take_forks(t_philo *philo, int left_fork, int right_fork)
{
	t_data	*data;
	int		result;

	data = philo->data;
	if (data->dead)
	{
		put_down_forks(philo, left_fork, right_fork);
		return (1);
	}
	if (left_fork < right_fork)
		result = take_fork_pair(philo, left_fork, right_fork);
	else
		result = take_fork_pair(philo, right_fork, left_fork);
	if (result == 1)
	{
		put_down_forks(philo, left_fork, right_fork);
		return (1);
	}
	return (0);
}
