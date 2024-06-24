/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:00 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/06/24 12:52:56 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* シミュレーションデータの初期化 */
int	init_data(t_data *data, int argc, char **argv)
{
	if (check_data_values(argc, argv)) // 引数のチェック
		return (1);
	if (set_data_values(data, argc, argv)) // データの設定
		return (1);
	if (initialize_mutexes(data)) // ミューテックスの初期化
		return (1);
	data->start_time = get_time(); // シミュレーションの開始時間を取得
	return (0);
}

/* 哲学者構造体の初期化 */
t_philo	*init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * data->num_philos); // 哲学者配列のメモリを確保
	if (!philos)
		return (NULL);
	while (i < data->num_philos)
	{
		philos[i].id = i + 1;             // 哲学者のIDを設定
		philos[i].last_meal = get_time(); // 最後の食事時間を現在の時間に設定
		philos[i].meals_eaten = 0;        // 食事回数を0に設定
		philos[i].data = data;            // 共通データへのポインタを設定
		i++;
	}
	return (philos);
}

/* シミュレーションの開始 */
int	start_simulation(t_philo *philos)
{
	if (create_threads(philos)) // 哲学者スレッドの作成
		return (1);
	check_death(philos);  // 哲学者の死亡チェック
	join_threads(philos); // スレッドの終了待ち
	return (0);
}
