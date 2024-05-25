/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:13 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/25 14:41:17 by ootsuboyosh      ###   ########.fr       */
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

long long	ft_atoll(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (res * sign);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	sleep_for(long long duration)
{
	long long	start_time;
	long long	current_time;

	start_time = get_time();
	while ((current_time = get_time()) - start_time < duration)
		usleep(100); // 100 microseconds (0.1 milliseconds) each iteration
}

void	check_death(t_philo *philos)
{
	int			i;
	long long	current_time;

	while (!philos->data->all_ate)
	{
		i = 0;
		while (i < philos->data->num_philos && !philos->data->dead)
		{
			pthread_mutex_lock(&philos->data->meal_mutex);
			current_time = get_time();
			if (current_time - philos[i].last_meal > philos->data->time_to_die)
			{
				print_action(&philos[i], "died");
				philos->data->dead = 1;
				pthread_mutex_unlock(&philos->data->meal_mutex);
				printf("Philosopher %d died at %lld\n", philos[i].id,
					current_time);
				return ; // 哲学者が死んだ後、即座に関数を抜ける
			}
			pthread_mutex_unlock(&philos->data->meal_mutex);
			usleep(100);
			i++;
		}
		i = 0;
		while (philos->data->num_must_eat != -1 && i < philos->data->num_philos
			&& philos[i].meals_eaten >= philos->data->num_must_eat)
			i++;
		if (i == philos->data->num_philos)
		{
			philos->data->all_ate = 1;
			break ;
		}
	}
	pthread_mutex_unlock(&philos->data->print_mutex);
}
