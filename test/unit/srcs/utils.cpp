#include "gtest/gtest.h"
extern "C"
{
// C言語のヘッダーファイルや関数の宣言
#include "philo.h"

}

TEST(GetCurrentTimeMsTest, ReturnsNonNegative)
{
	long	time_ms;

	time_ms = get_current_time_ms();
	EXPECT_GE(time_ms, 0);
}

TEST(GetCurrentTimeMsTest, ReturnsIncreasingValues)
{
	long	time_ms1;
	long	time_ms2;

	time_ms1 = get_current_time_ms();
	usleep(1000); // Sleep for 1 millisecond
	time_ms2 = get_current_time_ms();
	EXPECT_LT(time_ms1, time_ms2);
}
