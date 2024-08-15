/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:00 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/08/15 15:45:29 by ootsuboyosh      ###   ########.fr       */
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
		if (attempt_to_take_forks(philo, left_fork, right_fork) == 1)
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
