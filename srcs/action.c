/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:33:48 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/18 20:33:49 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	print_status(t_philosopher *philosopher, char *status)
{
	pthread_mutex_lock(&philosopher->table->print_mutex);
	if (!philosopher->table->simulation_ended)
		printf("%ld %d %s\n", get_current_time_ms(), philosopher->id, status);
	pthread_mutex_unlock(&philosopher->table->print_mutex);
}

void	think(t_philosopher *philosopher)
{
	print_status(philosopher, "is thinking");
}

void	eat(t_philosopher *philosopher, t_table *table)
{
	if (philosopher->id % 2 == 0) // 偶数IDのフィロソファーは右のフォークを先に取る
	{
		pthread_mutex_lock(philosopher->right_fork);
		print_status(philosopher, "has taken a fork");
		pthread_mutex_lock(philosopher->left_fork);
		print_status(philosopher, "has taken a fork");
	}
	else // 奇数IDのフィロソファーは左のフォークを先に取る
	{
		pthread_mutex_lock(philosopher->left_fork);
		print_status(philosopher, "has taken a fork");
		pthread_mutex_lock(philosopher->right_fork);
		print_status(philosopher, "has taken a fork");
	}
	philosopher->last_meal_time = get_current_time_ms();
	print_status(philosopher, "is eating");
	usleep(table->time_to_eat * 1000);
	philosopher->meals_eaten++;
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}

void	sleep_philosopher(t_philosopher *philosopher, t_table *table)
{
	print_status(philosopher, "is sleeping");
	usleep(table->time_to_sleep * 1000);
}
