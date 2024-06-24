/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:00 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/06/24 13:02:12 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 哲学者のルーチンを実行 */
void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;   // 引数を哲学者構造体にキャスト
	run_philo_routine(philo); // 哲学者のルーチンを実行
	return (NULL);
}

/* 哲学者のルーチンを定義 */
void	run_philo_routine(t_philo *philo)
{
	t_data	*data;
	int		left_fork;
	int		right_fork;

	data = philo->data;
	left_fork = philo->id - 1;                 // 左のフォークのインデックス
	right_fork = philo->id % data->num_philos; // 右のフォークのインデックス
	while (!data->dead && (data->num_must_eat == -1
			|| philo->meals_eaten < data->num_must_eat))
	// 哲学者が死んでおらず、食事回数の条件を満たしていない間ループ
	{
		if (data->dead)
			return ;
		if (philo->id % 2 == 0)
			usleep(100);                              // 偶数のIDの哲学者は少し待機
		take_forks(philo, left_fork, right_fork);     // フォークを取る
		perform_eating(philo, data);                  // 食事を行う
		put_down_forks(philo, left_fork, right_fork); // フォークを置く
		if (data->dead)
			return ;
		perform_sleeping(philo, data); // 睡眠を行う
		if (data->dead)
			return ;
		print_action(philo, "is thinking"); // 考えているアクションを出力
	}
}

/* 哲学者がフォークを取る */
void	take_forks(t_philo *philo, int left_fork, int right_fork)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->forks[left_fork]); // 左のフォークのミューテックスをロック
	print_action(philo, "has taken a fork");     // フォークを取ったアクションを出力
	if (data->num_philos == 1)                   // 哲学者が1人の場合
	{
		usleep(data->time_to_die * 1000);              // 哲学者が死ぬまで待機
		pthread_mutex_unlock(&data->forks[left_fork]); // フォークのミューテックスをアンロック
		return ;
	}
	pthread_mutex_lock(&data->forks[right_fork]); // 右のフォークのミューテックスをロック
	print_action(philo, "has taken a fork");      // フォークを取ったアクションを出力
}
