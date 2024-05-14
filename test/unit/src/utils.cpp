#include "gtest/gtest.h"
extern "C"
{
// C言語のヘッダーファイルや関数の宣言
#include "utils.h"

}

TEST(GetCurrentTimeTest, SetsTimevalCorrectly)
{
	struct timeval before, after, result;
	// 関数を呼び出す前の時間を取得
	gettimeofday(&before, NULL);
	// 関数をテスト
	get_current_time(&result);
	// 関数を呼び出した後の時間を取得
	gettimeofday(&after, NULL);
	// 関数が正しく時間を設定したことを確認
	EXPECT_TRUE(result.tv_sec >= before.tv_sec
		&& result.tv_sec <= after.tv_sec);
}

TEST(GetTimeDiffTest, ReturnsCorrectDifference)
{
	struct timeval	start;
	struct timeval	end;
	long			diff;

	// startとendの時間を設定します。
	start.tv_sec = 1;
	start.tv_usec = 500000; // 0.5秒
	end.tv_sec = 2;
	end.tv_usec = 200000; // 0.2秒
	// get_time_diff関数を呼び出し、結果を検証します。
	diff = get_time_diff(&start, &end);
	EXPECT_EQ(diff, 700); // 期待される差は700ミリ秒です。
}

TEST(LogPhilosopherActionTest, LogsCorrectMessage)
{
	t_philosopher	philo;
	FILE			*temp_stdout;
	FILE			*temp;
	char			output[100];
	char			expected_output[100];

	// philoの初期化...
	// stdoutを一時ファイルにリダイレクトします。
	temp_stdout = stdout;
	stdout = fopen("temp.txt", "w");
	// テスト対象の関数を呼び出します。
	log_philosopher_action(&philo, "is thinking");
	// stdoutを元に戻します。
	fclose(stdout);
	stdout = temp_stdout;
	// 一時ファイルから出力を読み取ります。
	temp = fopen("temp.txt", "r");
	fgets(output, 100, temp);
	fclose(temp);
	// 出力が期待通りであることを確認します。
	// ここでは、哲学者のIDとアクションが正しくログに記録されていることを確認します。
	// タイムスタンプはテスト実行時に依存するため、このテストでは確認しません。
	sprintf(expected_output, " %d is thinking\n", philo.id);
	EXPECT_TRUE(strstr(output, expected_output) != NULL);
}
