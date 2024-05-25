#include "gtest/gtest.h"
extern "C"
{
// C言語のヘッダーファイルや関数の宣言
#include "philo.h"
#include <stdio.h>

}

// テスト用のダミーデータを設定
t_table	create_table(int num_philosophers, int time_to_die, int time_to_eat,
		int time_to_sleep, int num_meals)
{
	t_table	table;

	table.number_of_philosophers = num_philosophers;
	table.time_to_die = time_to_die;
	table.time_to_eat = time_to_eat;
	table.time_to_sleep = time_to_sleep;
	table.nm_of_t_each_philo_must_eat = num_meals;
	table.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* num_philosophers);
	table.philosophers = (t_philosopher *)malloc(sizeof(t_philosopher)
			* num_philosophers);
	for (int i = 0; i < num_philosophers; i++)
	{
		pthread_mutex_init(&table.forks[i], NULL);
		table.philosophers[i].id = i + 1;
		table.philosophers[i].left_fork = &table.forks[i];
		table.philosophers[i].right_fork = &table.forks[(i + 1)
			% num_philosophers];
		table.philosophers[i].meals_eaten = 0;
		table.philosophers[i].table = &table;
	}
	return (table);
}

void	destroy_table(t_table &table)
{
	for (int i = 0; i < table.number_of_philosophers; i++)
	{
		pthread_mutex_destroy(&table.forks[i]);
	}
	free(table.forks);
	free(table.philosophers);
}

// テストケースの作成
TEST(PhilosopherTest, PhilosopherActions)
{
	t_table table = create_table(5, 800, 200, 200, 3);

	pthread_t thread;
	pthread_create(&thread, NULL, philosopher_thread, &table.philosophers[0]);
	sleep(2);               // 哲学者が十分に動作する時間を確保するためにスリープ
	pthread_cancel(thread); // スレッドをキャンセル
	pthread_join(thread, NULL);

	// 哲学者の行動が期待通りか確認
	EXPECT_GE(table.philosophers[0].meals_eaten, 1);

	destroy_table(table);
}