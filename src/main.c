/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:08:07 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/10 12:10:26 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.c

#include "philo.h"
#include "philosopher.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int	main(int argc, char **argv)
{
	t_philo_data	philo_data;
	pthread_t		*threads;
	int				i;
	t_philosopher	*philo;

	i = 0;
	// 引数を解析してプログラムの設定を行う
	if (parse_arguments(argc, argv, &philo_data) != 0)
		return (1);
	// ミューテックスおよびシミュレーション開始時刻の初期化
	pthread_mutex_init(&philo_data.write_mutex, NULL);
	gettimeofday(&philo_data.simulation_start, NULL);
	philo_data.forks_mutexes = malloc(sizeof(pthread_mutex_t)
			* philo_data.number_of_philosophers);
	while (i < philo_data.number_of_philosophers)
	{
		pthread_mutex_init(&philo_data.forks_mutexes[i], NULL);
		i++;
	}
	// 哲学者スレッドの作成と実行
	threads = malloc(sizeof(pthread_t) * philo_data.number_of_philosophers);
	i = 0; // インデックスをリセット
	while (i < philo_data.number_of_philosophers)
	{
		philo = malloc(sizeof(t_philosopher));
		philo->id = i + 1;
		philo->state = THINKING;
		philo->times_eaten = 0;
		philo->last_meal_time = philo_data.simulation_start;
		philo->left_fork_mutex = &philo_data.forks_mutexes[i];
		philo->right_fork_mutex = &philo_data.forks_mutexes[(i + 1)
			% philo_data.number_of_philosophers];
		philo->shared_data = &philo_data;
		if (pthread_create(&threads[i], NULL, &philosopher_routine, philo) != 0)
		{
			fprintf(stderr,
					"Error: Could not create thread for philosopher \
				%d\n",
					i + 1);
			return (1);
		}
		i++;
	}
	// スレッドの終了を待つ
	i = 0; // インデックスをリセット
	while (i < philo_data.number_of_philosophers)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	// リソースの解放
	pthread_mutex_destroy(&philo_data.write_mutex);
	i = 0; // インデックスをリセット
	while (i < philo_data.number_of_philosophers)
	{
		pthread_mutex_destroy(&philo_data.forks_mutexes[i]);
		i++;
	}
	free(threads);
	free(philo_data.forks_mutexes);
	return (0);
}
