/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:00 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/26 18:06:38 by ootsuboyosh      ###   ########.fr       */
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
		if (data->dead)
			return ;
		if (philo->id % 2 == 0)
			usleep(100);
		take_forks(philo, left_fork, right_fork);
		perform_eating(philo, data);
		put_down_forks(philo, left_fork, right_fork);
		if (data->dead)
			return ;
		perform_sleeping(philo, data);
		if (data->dead)
			return ;
		print_action(philo, "is thinking");
	}
}

void	take_forks(t_philo *philo, int left_fork, int right_fork)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->forks[left_fork]);
	print_action(philo, "has taken a fork");
	if (data->num_philos == 1)
	{
		usleep(data->time_to_die * 1000);
		pthread_mutex_unlock(&data->forks[left_fork]);
		return ;
	}
	pthread_mutex_lock(&data->forks[right_fork]);
	print_action(philo, "has taken a fork");
}
