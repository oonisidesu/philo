/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:13 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/06/24 14:09:56 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/* データ構造体: シミュレーションの共通データを保持 */
typedef struct s_data
{
	int num_philos;              // 哲学者の数
	long time_to_die;            // 哲学者が死ぬまでの時間（ミリ秒）
	long time_to_eat;            // 食事の時間（ミリ秒）
	long time_to_sleep;          // 睡眠の時間（ミリ秒）
	int num_must_eat;            // 哲学者が食べるべき回数
	int all_ate;                 // 全員が食べ終わったかのフラグ
	int dead;                    // 哲学者が死んだかのフラグ
	pthread_mutex_t *forks;      // フォークのミューテックス配列
	pthread_mutex_t print_mutex; // 出力用のミューテックス
	pthread_mutex_t meal_mutex;  // 食事用のミューテックス
	pthread_mutex_t dead_mutex;  // 死亡判定用のミューテックス
	long start_time;             // シミュレーションの開始時間
}		t_data;

/* 哲学者構造体: 各哲学者のデータを保持 */
typedef struct s_philo
{
	int id;           // 哲学者のID
	long last_meal;   // 最後の食事の時間
	int meals_eaten;  // 食事の回数
	pthread_t thread; // 哲学者のスレッド
	t_data *data;     // 共通データへのポインタ
}		t_philo;

/* エラーメッセージを出力 */
int		print_error(char *msg);

/* 文字列をlong型に変換 */
long	ft_atoll(const char *str);

/* 現在の時間をミリ秒で取得 */
long	get_time(void);

/* 哲学者のアクションを出力 */
void	print_action(t_philo *philo, char *action);

/* メモリを解放 */
void	free_all(t_philo *philos);

/* 指定時間スリープ */
void	sleep_for(long duration);

/* データ初期化関数群 */
int		init_data(t_data *data, int argc, char **argv);
int		check_data_values(int argc, char **argv);
int		set_data_values(t_data *data, int argc, char **argv);
int		initialize_mutexes(t_data *data);

/* 哲学者の初期化 */
t_philo	*init_philos(t_data *data);

/* シミュレーションの開始 */
int		start_simulation(t_philo *philos);

/* スレッド作成 */
int		create_threads(t_philo *philos);

/* スレッド終了を待機 */
void	join_threads(t_philo *philos);

/* 哲学者のルーチン関数 */
void	*philo_routine(void *arg);

/* 哲学者のルーチン実行 */
void	run_philo_routine(t_philo *philo);

/* フォークを取る */
void	take_forks(t_philo *philo, int left_fork, int right_fork);

/* フォークを置く */
void	put_down_forks(t_philo *philo, int left_fork, int right_fork);

/* 食事を行う */
void	perform_eating(t_philo *philo, t_data *data);

/* 睡眠を行う */
void	perform_sleeping(t_philo *philo, t_data *data);

/* 死亡をチェック */
void	check_death(t_philo *philos);

/* 各哲学者の状態をチェック */
int		check_each_philo(t_philo *philos);

/* 全哲学者が食事を終えたかチェック */
void	check_all_ate(t_philo *philos);

#endif
