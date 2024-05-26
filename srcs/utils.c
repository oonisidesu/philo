/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:13 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/26 16:33:10 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *msg)
{
	printf("Error: %s\n", msg);
	return (1);
}

long long	get_time(void)
{
	struct timeval	tv;
	long long		time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_in_ms);
}

void	print_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->dead)
		printf("%lld %d %s\n", get_time() - philo->data->start_time, philo->id,
			action);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	free_all(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->num_philos)
	{
		pthread_mutex_destroy(&philos->data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&philos->data->print_mutex);
	pthread_mutex_destroy(&philos->data->meal_mutex);
	pthread_mutex_destroy(&philos->data->dead_mutex);
	free(philos->data->forks);
	free(philos);
}

void	sleep_for(long long duration)
{
	long long	start_time;
	long long	current_time;

	start_time = get_time();
	current_time = start_time;
	while (current_time - start_time < duration)
	{
		usleep(100);
		current_time = get_time();
	}
}
