/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:00 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/06/24 12:57:57 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

/* 引数の値が有効かチェックする */
int	check_data_values(int argc, char **argv)
{
	int		i;
	long	value;

	i = 1;
	while (i < argc)
	{
		value = ft_atoll(argv[i]);         // 文字列をlong型に変換
		if (value <= 0 || value > INT_MAX) // 値が範囲内かチェック
		{
			print_error("Argument value out of range"); // 範囲外の場合エラーメッセージを出力
			return (1);
		}
		i++;
	}
	return (0);
}

/* 引数からデータ構造体に値を設定する */
int	set_data_values(t_data *data, int argc, char **argv)
{
	data->num_philos = ft_atoll(argv[1]);    // 哲学者の数を設定
	data->time_to_die = ft_atoll(argv[2]);   // 死ぬまでの時間を設定
	data->time_to_eat = ft_atoll(argv[3]);   // 食事の時間を設定
	data->time_to_sleep = ft_atoll(argv[4]); // 睡眠の時間を設定
	if (argc == 6)
		data->num_must_eat = ft_atoll(argv[5]); // 食べるべき回数を設定
	else
		data->num_must_eat = -1;
	// デフォルト値を設定
	data->all_ate = 0;
	// 全員が食べ終わったかのフラグを初期化
	data->dead = 0;
	// 死亡フラグを初期化
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	// フォークのミューテックス配列を確保
	if (!data->forks)
		return (print_error("Memory allocation failed"));
	// メモリ確保に失敗した場合エラーメッセージを出力
	return (0);
}

/* ミューテックスを初期化する */
int	initialize_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL); // フォークのミューテックスを初期化
		i++;
	}
	pthread_mutex_init(&data->print_mutex, NULL); // 出力用ミューテックスを初期化
	pthread_mutex_init(&data->meal_mutex, NULL);  // 食事用ミューテックスを初期化
	pthread_mutex_init(&data->dead_mutex, NULL);  // 死亡判定用ミューテックスを初期化
	return (0);
}

/* 哲学者のスレッドを作成する */
int	create_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->num_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]))
			// スレッドを作成
			return (print_error("Thread creation failed"));
		// 作成に失敗した場合エラーメッセージを出力
		i++;
	}
	return (0);
}

/* 哲学者のスレッドを結合する */
void	join_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->num_philos)
	{
		pthread_join(philos[i].thread, NULL); // スレッドの終了を待機
		i++;
	}
}
