/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:15:37 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/13 15:04:38 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// philosopher.c

#include "philosopher.h"
#include "utils.h"
#include <stdio.h>
#include <unistd.h>

// 哲学者がフォークを取る関数
void	take_forks(t_philosopher *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->id % 2 == 0)
	{
		first_fork = philo->right_fork_mutex;
		second_fork = philo->left_fork_mutex;
	}
	else
	{
		first_fork = philo->left_fork_mutex;
		second_fork = philo->right_fork_mutex;
	}
	pthread_mutex_lock(first_fork);
	log_philosopher_action(philo, "has taken a fork");
	pthread_mutex_lock(second_fork);
	log_philosopher_action(philo, "has taken a fork");
}

// 哲学者が食事をする関数
void	eat(t_philosopher *philo)
{
	philo->state = EATING;
	log_philosopher_action(philo, "is eating");
	get_current_time(&philo->last_meal_time);
	usleep(philo->shared_data->time_to_eat * 1000);
	philo->times_eaten++;
}

// 哲学者がフォークを置く関数
void	drop_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	log_philosopher_action(philo, "has dropped the forks");
}

// 哲学者が睡眠と思考をする関数
void	sleep_and_think(t_philosopher *philo)
{
	philo->state = SLEEPING;
	log_philosopher_action(philo, "is sleeping");
	usleep(philo->shared_data->time_to_sleep * 1000);
	philo->state = THINKING;
	log_philosopher_action(philo, "is thinking");
}

// 哲学者の死亡をチェックする関数
void	check_death(t_philosopher *philo, struct timeval current_time)
{
	long	time_since_last_meal;

	time_since_last_meal = get_time_diff(&philo->last_meal_time, &current_time);
	if (time_since_last_meal > philo->shared_data->time_to_die)
	{
		philo->state = DEAD;
		log_philosopher_action(philo, "died");
		// ここでシミュレーションを終了するための処理を追加する必要がある
		
	}
}

// コマンドライン引数を解析し、プログラムの設定を行う関数
int	parse_arguments(int argc, char **argv, t_philo_data *philo_data)
{
	if (argc < 5 || argc > 6)
	{
		write(STDERR_FILENO, "Usage:", 6);
		write(STDERR_FILENO, " philo", 6);
		write(STDERR_FILENO, " [number_of_philosopher]", 24);
		write(STDERR_FILENO, " [time_to_die]", 14);
		write(STDERR_FILENO, " [time_to_eat]", 14);
		write(STDERR_FILENO, " [time_to_sleep]", 16);
		write(STDERR_FILENO, " [number_of_times_", 18);
		write(STDERR_FILENO, "each_philosopher_must_eat]\n", 28);
		return (1);
	}
	philo_data->number_of_philosophers = ft_atoi(argv[1]);
	philo_data->time_to_die = ft_atoi(argv[2]);
	philo_data->time_to_eat = ft_atoi(argv[3]);
	philo_data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		philo_data->num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	}
	else
	{
		philo_data->num_of_times_each_philo_must_eat = -1;
	}
	return (0);
}

// 哲学者スレッドのメインルーチン
void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;
	struct timeval	current_time;

	philo = (t_philosopher *)arg;
	while (philo->state != DEAD)
	{
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		sleep_and_think(philo);
		get_current_time(&current_time);
		check_death(philo, current_time);
		// オプショナル引数で指定された食事回数に達したかのチェックも必要
	}
	return (NULL);
}
