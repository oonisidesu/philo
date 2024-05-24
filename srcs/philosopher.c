/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:33:30 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/18 20:33:31 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	*philosopher_thread(void *arg)
{
	t_philosopher	*philosopher;
	t_table			*table;

	philosopher = (t_philosopher *)arg;
	table = philosopher->table;
	while (!table->simulation_ended)
	{
		think(philosopher);
		eat(philosopher, table);
		sleep_philosopher(philosopher, table);
		usleep(100); // 短い待機を追加して無限ループを防止
	}
	return (NULL);
}

void	monitor_philosophers(t_table *table)
{
	int		i;
	long	current_time;
	int		all_ate;

	while (!table->simulation_ended)
	{
		i = 0;
		all_ate = 1;
		while (i < table->number_of_philosophers)
		{
			current_time = get_current_time_ms();
			if (current_time
				- table->philosophers[i].last_meal_time > table->time_to_die)
			{
				print_status(&table->philosophers[i], "died");
				table->simulation_ended = 1;
				break ;
			}
			if (table->nm_of_t_each_philo_must_eat != -1
				&& table->philosophers[i].meals_eaten < table->nm_of_t_each_philo_must_eat)
			{
				all_ate = 0;
			}
			i++;
		}
		if (all_ate && table->nm_of_t_each_philo_must_eat != -1)
		{
			table->simulation_ended = 1;
		}
		usleep(1000); // モニタリングループの短い待機を追加して無限ループを防止
	}
}
