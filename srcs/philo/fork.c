/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:12:41 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/07 17:07:46 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	acquire_forks(int philosopher_id, pthread_mutex_t *fork_mutexes,
		t_simulation_params *params)
{
	int	left_fork;
	int	right_fork;

	// 哲学者IDに基づいて左右のフォークのインデックスを計算
	left_fork = philosopher_id;
	right_fork = (philosopher_id + 1) % params->num_philosophers;
	// デッドロックを避けるための戦略を適用
	// 例: 哲学者IDが奇数の場合は左のフォークから、偶数の場合は右のフォークから取得する
	if (philosopher_id % 2 == 0)
	{
		// 偶数IDの哲学者は右のフォークから取得
		pthread_mutex_lock(&fork_mutexes[right_fork]);
		pthread_mutex_lock(&fork_mutexes[left_fork]);
	}
	else
	{
		// 奇数IDの哲学者は左のフォークから取得
		pthread_mutex_lock(&fork_mutexes[left_fork]);
		pthread_mutex_lock(&fork_mutexes[right_fork]);
	}
	// この時点で、哲学者は食事をするための両方のフォークを取得している
}

void	release_forks(int philosopher_id, pthread_mutex_t *fork_mutexes,
		t_simulation_params *params)
{
	int	left_fork;
	int	right_fork;

	// 哲学者IDに基づいて左右のフォークのインデックスを計算
	left_fork = philosopher_id;
	right_fork = (philosopher_id + 1) % params->num_philosophers;
	// 左右のフォークのミューテックスをアンロック
	pthread_mutex_unlock(&fork_mutexes[left_fork]);
	pthread_mutex_unlock(&fork_mutexes[right_fork]);
}
