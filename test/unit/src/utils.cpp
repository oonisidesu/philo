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
