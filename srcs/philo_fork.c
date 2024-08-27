/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:44:44 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/08/27 15:58:46 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	attempt_to_take_forks(t_philo *philo, int left_fork, int right_fork)
{
	long	time;
	long	delay;

	time = get_time();
	delay = time % 100;
	usleep(delay + 50);
	if (philo->id % 2 == 0)
	{
		usleep(100);
		if (take_forks(philo, left_fork, right_fork) == 1)
			return (1);
	}
	else
	{
		if (take_forks(philo, right_fork, left_fork) == 1)
			return (1);
	}
	return (0);
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
	result = take_fork_pair(philo, left_fork, right_fork);
	if (result == 1)
	{
		put_down_forks(philo, left_fork, right_fork);
		return (1);
	}
	return (0);
}
