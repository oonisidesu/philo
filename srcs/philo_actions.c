/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:00 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/08/10 15:44:09 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	put_down_forks(t_philo *philo, int left_fork, int right_fork)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_unlock(&data->forks[left_fork]);
	pthread_mutex_unlock(&data->forks[right_fork]);
	if (philo->data->dead)
		return (1);
	return (0);
}

int	perform_eating(t_philo *philo, t_data *data)
{
	if (philo->data->dead)
		return (1);
	print_action(philo, "is eating");
	pthread_mutex_lock(&data->meal_mutex);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->meal_mutex);
	sleep_for(data->time_to_eat);
	return (0);
}

int	perform_sleeping(t_philo *philo, t_data *data)
{
	if (philo->data->dead)
		return (1);
	print_action(philo, "is sleeping");
	sleep_for(data->time_to_sleep);
	return (0);
}
