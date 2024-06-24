/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:35:50 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/06/24 12:48:15 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo *philos; // 哲学者の配列へのポインタ
	t_data data;     // シミュレーションの共通データ
	// 引数の数をチェック、5または6でなければエラーメッセージを出力
	if (argc != 5 && argc != 6)
		return (print_error("Invalid number of arguments"));
	// シミュレーションのデータを初期化、失敗した場合はエラーメッセージを出力
	if (init_data(&data, argc, argv))
		return (1);
	// 哲学者の配列を初期化、失敗した場合はエラーメッセージを出力
	philos = init_philos(&data);
	if (!philos)
		return (1);
	// シミュレーションを開始、失敗した場合はエラーメッセージを出力
	if (start_simulation(philos))
		return (1);
	// 使用したメモリを解放
	free_all(philos);
	return (0);
}
