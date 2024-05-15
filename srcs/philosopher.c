/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:06:25 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/14 17:36:40 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	think(t_philosopher *philosopher)
{
	printf("%ld %d is thinking\n", get_current_time_ms(), philosopher->id);
}

void	eat(t_philosopher *philosopher, t_table *table)
{
	pthread_mutex_lock(philosopher->left_fork);
	pthread_mutex_lock(philosopher->right_fork);
	philosopher->last_meal_time = get_current_time_ms();
	printf("%ld %d is eating\n", philosopher->last_meal_time, philosopher->id);
	usleep(table->time_to_eat * 1000);
	philosopher->meals_eaten++;
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}

void	sleep_philosopher(t_philosopher *philosopher, t_table *table)
{
	printf("%ld %d is sleeping\n", get_current_time_ms(), philosopher->id);
	usleep(table->time_to_sleep * 1000);
}

void	*philosopher_thread(void *arg)
{
	t_philosopher	*philosopher;
	t_table			*table;

	philosopher = (t_philosopher *)arg;
	table = philosopher->table;
	while (1)
	{
		think(philosopher);
		eat(philosopher, table);
		sleep_philosopher(philosopher, table);
		if (philosopher->meals_eaten >= table->nm_of_t_each_philo_must_eat)
			break ;
	}
	return (NULL);
}
