#include <gtest/gtest.h>
#include <limits.h>
#include <unistd.h>

// プロトタイプ宣言
extern "C"
{
	int check_args_num(int argc);
	int check_front_zero_next(int argc, char *argv[]);
	int check_int(int argc, char *argv[]);
	long test_extract_integer(char *s, long sign);
}

// test_extract_integerのテスト
TEST(ExtractIntegerTest, PositiveNumber)
{
	char	num1[] = "123";

	EXPECT_EQ(test_extract_integer(num1, 1), 123);
}

TEST(ExtractIntegerTest, NegativeNumber)
{
	char	num2[] = "123";

	EXPECT_EQ(test_extract_integer(num2, -1), -123);
}

TEST(ExtractIntegerTest, Overflow)
{
	char	num3[] = "2147483648";

	EXPECT_EQ(test_extract_integer(num3, 1), LONG_MAX);
}

TEST(ExtractIntegerTest, Underflow)
{
	char	num4[] = "2147483649";

	EXPECT_EQ(test_extract_integer(num4, -1), LONG_MIN);
}

// check_args_numのテスト
TEST(CheckArgsNumTest, ValidArgs)
{
	EXPECT_EQ(check_args_num(5), 0);
}

TEST(CheckArgsNumTest, TooFewArgs)
{
	EXPECT_EQ(check_args_num(4), 1);
}

TEST(CheckArgsNumTest, TooManyArgs)
{
	EXPECT_EQ(check_args_num(7), 1);
}

// check_front_zero_nextのテスト
TEST(CheckFrontZeroNextTest, ValidArgs)
{
	const char	*argv1[] = {"program", "1", "10", "100", "1000"};

	EXPECT_EQ(check_front_zero_next(5, (char **)argv1), 0);
}

TEST(CheckFrontZeroNextTest, InvalidArgs)
{
	const char	*argv2[] = {"program", "01", "10", "100", "1000"};

	EXPECT_EQ(check_front_zero_next(5, (char **)argv2), 1);
}

// check_intのテスト
TEST(CheckIntTest, ValidArgs)
{
	const char	*argv1[] = {"program", "1", "10", "100", "1000"};

	EXPECT_EQ(check_int(5, (char **)argv1), 0);
}

TEST(CheckIntTest, NonNumericArg)
{
	const char	*argv2[] = {"program", "1", "10", "100", "10a0"};

	EXPECT_EQ(check_int(5, (char **)argv2), 1);
}

TEST(CheckIntTest, ExceedsIntMax)
{
	const char	*argv3[] = {"program", "2147483648", "10", "100", "1000"};

	EXPECT_EQ(check_int(5, (char **)argv3), 1);
}
