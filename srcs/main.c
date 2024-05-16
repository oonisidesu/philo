/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:00:29 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/15 19:32:43 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	init_table(t_table *table, int argc, char *argv[])
{
	int	i;

	table->number_of_philosophers = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->nm_of_t_each_philo_must_eat = ft_atoi(argv[5]);
	else
		table->nm_of_t_each_philo_must_eat = -1;
	table->forks = malloc(sizeof(pthread_mutex_t)
			* table->number_of_philosophers);
	table->philosophers = malloc(sizeof(t_philosopher)
			* table->number_of_philosophers);
	if (!table->forks || !table->philosophers)
		return (1);
	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

static void	init_philosophers(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		table->philosophers[i].id = i + 1;
		table->philosophers[i].left_fork = &table->forks[i];
		table->philosophers[i].right_fork = &table->forks[(i + 1)
			% table->number_of_philosophers];
		table->philosophers[i].last_meal_time = get_current_time_ms();
		table->philosophers[i].meals_eaten = 0;
		table->philosophers[i].table = table;
		pthread_create(&table->philosophers[i].thread, NULL, philosopher_thread,
			&table->philosophers[i]);
		i++;
	}
}

static void	join_philosophers(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_join(table->philosophers[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
	free(table->philosophers);
}

static int	check_args(int argc, char *argv[])
{
	if (check_args_num(argc))
		return (1);
	if (check_front_zero_next(argc, argv))
		return (1);
	if (check_int(argc, argv))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	if (check_args(argc, argv))
		return (1);
	if (init_table(&table, argc, argv) != 0)
		return (1);
	init_philosophers(&table);
	join_philosophers(&table);
	return (0);
}
