/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:05:53 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/07 17:56:41 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdbool.h>

void	*philosopher(void *arg)
{
	int	philosopher_id;

	philosopher_id = *((int *)arg);
	while (true)
	{
		log_state_change(philosopher_id, "thinking", get_current_timestamp());
		simulate_think(params);
		acquire_forks(philosopher_id, fork_mutexes, params);
		log_state_change(philosopher_id, "eating", get_current_timestamp());
		simulate_eat(params);
		release_forks(philosopher_id, fork_mutexes, params);
		log_state_change(philosopher_id, "sleeping", get_current_timestamp());
		simulate_sleep(params);
	}
	return (NULL);
}

void	simulate_philosophers(t_simulation_params *params)
{
	pthread_t		*philosophers;
	pthread_mutex_t	*fork_mutexes;
	int				*ids;
	int				num_philosophers;
	int				i;
	int				j;

	num_philosophers = params->num_philosophers;
	i = 0;
	philosophers = malloc(num_philosophers * sizeof(pthread_t));
	fork_mutexes = malloc(num_philosophers * sizeof(pthread_mutex_t));
	ids = malloc(num_philosophers * sizeof(int));
	if (!philosophers || !fork_mutexes || !ids)
	{
		// エラーハンドリング: メモリ確保失敗
		free(philosophers);
		free(fork_mutexes);
		free(ids);
		return ;
	}
	// ミューテックスの初期化
	i = 0;
	while (i < num_philosophers)
	{
		pthread_mutex_init(&fork_mutexes[i], NULL);
		i++;
	}
	// 哲学者スレッドの作成
	i = 0;
	while (i < num_philosophers)
	{
		ids[i] = i;
		if (pthread_create(&philosophers[i], NULL, philosopher, &ids[i]) != 0)
		{
			// エラーハンドリング: スレッド作成失敗
			// 既に初期化されたミューテックスのクリーンアップが必要
			j = 0;
			while (j < i)
			{
				pthread_mutex_destroy(&fork_mutexes[j]);
				j++;
			}
			free(philosophers);
			free(fork_mutexes);
			free(ids);
			return ;
		}
		i++;
	}
	// すべての哲学者スレッドが終了するのを待つ
	i = 0;
	while (i < num_philosophers)
	{
		pthread_join(philosophers[i], NULL);
		i++;
	}
	// ミューテックスの破棄
	i = 0;
	while (i < num_philosophers)
	{
		pthread_mutex_destroy(&fork_mutexes[i]);
		i++;
	}
	free(philosophers);
	free(fork_mutexes);
	free(ids);
}
