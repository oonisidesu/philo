/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:13 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/06/24 12:51:11 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* エラーメッセージを表示し、1を返す */
int	print_error(char *msg)
{
	printf("Error: %s\n", msg);
	return (1);
}

/* 現在の時間をミリ秒単位で取得 */
long	get_time(void)
{
	struct timeval	tv;
	long			time_in_ms;

	gettimeofday(&tv, NULL);                               // 現在の時間を取得
	time_in_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000); // ミリ秒に変換
	return (time_in_ms);
}

/* 哲学者のアクションを表示 */
void	print_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->data->print_mutex); // 出力のミューテックスをロック
	if (!philo->data->dead)                        // 哲学者が死んでいない場合
		printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id,
				action);                              // アクションを表示
	pthread_mutex_unlock(&philo->data->print_mutex); // ミューテックスをアンロック
}

/* すべてのリソースを解放 */
void	free_all(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->num_philos)
	{
		pthread_mutex_destroy(&philos->data->forks[i]); // フォークのミューテックスを破棄
		i++;
	}
	pthread_mutex_destroy(&philos->data->print_mutex); // 出力のミューテックスを破棄
	pthread_mutex_destroy(&philos->data->meal_mutex);  // 食事のミューテックスを破棄
	pthread_mutex_destroy(&philos->data->dead_mutex);  // 死亡判定のミューテックスを破棄
	free(philos->data->forks);                         // フォークのミューテックス配列を解放
	free(philos);                                      // 哲学者の配列を解放
}

/* 指定された期間スリープ */
void	sleep_for(long duration)
{
	long	start_time;
	long	current_time;

	start_time = get_time(); // 開始時間を取得
	current_time = start_time;
	while (current_time - start_time < duration) // 指定された期間が経過するまでループ
	{
		usleep(100);               // 100マイクロ秒スリープ
		current_time = get_time(); // 現在の時間を更新
	}
}
