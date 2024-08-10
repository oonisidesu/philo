/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:13 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/08/10 16:16:19 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_philo *philos)
{
	while (!philos->data->all_ate)
	{
		if (check_each_philo(philos))
			return ;
		check_all_ate(philos);
		usleep(100);
	}
}

int	check_each_philo(t_philo *philos)
{
	int		i;
	long	current_time;

	i = 0;
	while (i < philos->data->num_philos && !philos->data->dead)
	{
		pthread_mutex_lock(&philos->data->meal_mutex);
		current_time = get_time();
		if (current_time - philos[i].last_meal > philos->data->time_to_die)
		{
			print_action(&philos[i], "died");
			pthread_mutex_lock(&philos->data->dead_mutex);
			philos->data->dead = 1;
			pthread_mutex_unlock(&philos->data->dead_mutex);
			pthread_mutex_unlock(&philos->data->meal_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philos->data->meal_mutex);
		i++;
	}
	return (0);
}

void	check_all_ate(t_philo *philos)
{
	int	i;

	i = 0;
	while (philos->data->num_must_eat != -1 && i < philos->data->num_philos
		&& philos[i].meals_eaten >= philos->data->num_must_eat)
		i++;
	if (i == philos->data->num_philos)
	{
		philos->data->all_ate = 1;
	}
}
