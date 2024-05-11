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