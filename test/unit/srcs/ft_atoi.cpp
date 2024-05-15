#include "gtest/gtest.h"
extern "C"
{
// C言語のヘッダーファイルや関数の宣言
#include "philo.h"
#include <stdio.h>

}

TEST(FT_ATOI_TEST, BasicTests)
{
	EXPECT_EQ(ft_atoi("12345"), atoi("12345"));
	EXPECT_EQ(ft_atoi("-67890"), atoi("-67890"));
	EXPECT_EQ(ft_atoi("0"), atoi("0"));
	EXPECT_EQ(ft_atoi("   42"), atoi("   42"));
	EXPECT_EQ(ft_atoi("+100"), atoi("+100"));
	EXPECT_EQ(ft_atoi("   -123  "), atoi("   -123  "));
	EXPECT_EQ(ft_atoi("abc123"), atoi("abc123")); // 非数値文字が含まれる場合
	EXPECT_EQ(ft_atoi("12abc34"), atoi("12abc34"));
	// 数値の途中に非数値文字が含まれる場合
	EXPECT_EQ(ft_atoi("  - 789"), atoi("  - 789"));             // 無効な符号
	EXPECT_EQ(ft_atoi("2147483647"), atoi("2147483647"));       // INT_MAX
	EXPECT_EQ(ft_atoi("-2147483648"), atoi("-2147483648"));     // INT_MIN
	EXPECT_EQ(ft_atoi("999999999999"), atoi("999999999999"));   // オーバーフロー
	EXPECT_EQ(ft_atoi("-999999999999"), atoi("-999999999999")); // アンダーフロー
}

TEST(FT_ATOI_TEST, EdgeCases)
{
	EXPECT_EQ(ft_atoi("9223372036854775808"),
				atoi("9223372036854775808")); // LONG_MAX + 1
	EXPECT_EQ(ft_atoi("9223372036854775806"),
				atoi("9223372036854775806")); // LONG_MAX - 1
	EXPECT_EQ(ft_atoi("-9223372036854775807"),
				atoi("-9223372036854775807")); // LONG_MIN + 1
	EXPECT_EQ(ft_atoi("-9223372036854775809"),
				atoi("-9223372036854775809")); // LONG_MIN - 1
	EXPECT_EQ(ft_atoi("9999999999999999999999"),
				atoi("9999999999999999999999")); // オーバーフロー大
	EXPECT_EQ(ft_atoi("-999999999999999999999"),
				atoi("-999999999999999999999")); // アンダーフロー大
}