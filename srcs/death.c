/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:13 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/06/24 13:37:16 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 全ての哲学者の死亡をチェックする関数 */
void	check_death(t_philo *philos)
{
	while (!philos->data->all_ate) // 全員が食べ終わるまでループ
	{
		if (check_each_philo(philos)) // 各哲学者の死亡をチェック
			return ;                   // 死亡が確認されたら終了
		check_all_ate(philos);        // 全員が食べ終わったかをチェック
		usleep(100);                  // 100ミリ秒待機
	}
}

/* 各哲学者の死亡をチェックする関数 */
int	check_each_philo(t_philo *philos)
{
	int		i;
	long	current_time;

	i = 0;
	while (i < philos->data->num_philos && !philos->data->dead) // 全哲学者をループ
	{
		pthread_mutex_lock(&philos->data->meal_mutex);
		// 食事のミューテックスをロック
		current_time = get_time();
		// 現在の時間を取得
		if (current_time - philos[i].last_meal > philos->data->time_to_die)
		// 最後の食事から時間が経ちすぎているかをチェック
		{
			print_action(&philos[i], "died");                // 死亡アクションを出力
			philos->data->dead = 1;                          // 死亡フラグを設定
			pthread_mutex_unlock(&philos->data->meal_mutex); // ミューテックスをアンロック
			return (1);                                      // 死亡が確認されたら1を返す
		}
		pthread_mutex_unlock(&philos->data->meal_mutex); // ミューテックスをアンロック
		i++;
	}
	return (0); // 全員無事なら0を返す
}

/* 全哲学者が食事を終えたかチェックする関数 */
void	check_all_ate(t_philo *philos)
{
	int	i;

	i = 0;
	while (philos->data->num_must_eat != -1 && i < philos->data->num_philos
		&& philos[i].meals_eaten >= philos->data->num_must_eat)
		// 指定された回数食事を終えた哲学者をカウント
		i++;
	if (i == philos->data->num_philos) // 全哲学者が食事を終えていたら
	{
		philos->data->all_ate = 1; // 全員が食べ終わったフラグを設定
	}
}
