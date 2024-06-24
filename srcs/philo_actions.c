/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:00 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/06/24 13:28:09 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* フォークを置く */
void	put_down_forks(t_philo *philo, int left_fork, int right_fork)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_unlock(&data->forks[left_fork]);  // 左のフォークのミューテックスをアンロック
	pthread_mutex_unlock(&data->forks[right_fork]); // 右のフォークのミューテックスをアンロック
}

/* 哲学者が食事を行う */
void	perform_eating(t_philo *philo, t_data *data)
{
	print_action(philo, "is eating");        // 食事をしているアクションを出力
	pthread_mutex_lock(&data->meal_mutex);   // 食事のミューテックスをロック
	philo->last_meal = get_time();           // 最後の食事時間を更新
	philo->meals_eaten++;                    // 食事回数をインクリメント
	pthread_mutex_unlock(&data->meal_mutex); // 食事のミューテックスをアンロック
	sleep_for(data->time_to_eat);            // 食事時間だけスリープ
}

/* 哲学者が睡眠を行う */
void	perform_sleeping(t_philo *philo, t_data *data)
{
	print_action(philo, "is sleeping"); // 睡眠をしているアクションを出力
	sleep_for(data->time_to_sleep);     // 睡眠時間だけスリープ
}
