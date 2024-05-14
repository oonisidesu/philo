/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:08:26 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/09 19:08:51 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// philo.h

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo_data
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_each_philo_must_eat;
	pthread_mutex_t write_mutex;     // ログ出力用のミューテックス
	struct timeval simulation_start; // シミュレーション開始時刻
	pthread_mutex_t *forks_mutexes;  // 各フォークのミューテックス配列
}		t_philo_data;

// 引数解析用の関数プロトタイプ
int		parse_arguments(int argc, char **argv, t_philo_data *philo_data);

// 哲学者の行動ルーチン関数プロトタイプ
void	*philosopher_routine(void *arg);

#endif // PHILO_H
