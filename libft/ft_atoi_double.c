/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:20:05 by yootsubo          #+#    #+#             */
/*   Updated: 2024/02/02 15:56:42 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skip_whitespace_signs(const char *str)
{
	while (*str == '\0' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	return ((char *)str);
}

static int	extract_sign(const char *str)
{
	int	sign;

	sign = 1;
	while (*str == '\0' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
		sign *= -1;
	return (sign);
}

static double	extract_integer(char *s)
{
	double	num;
	double	div;
	int		i;

	num = 0;
	div = 0.1;
	i = 0;
	while ('0' <= s[i] && s[i] <= '9')
	{
		num = (s[i] - '0') + num * 10.0;
		i++;
	}
	if (s[i] == '.' || i != 0)
		s++;
	if (i == 0)
		return (num);
	while ('0' <= s[i] && s[i] <= '9')
	{
		num = num + ((s[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	return (num);
}

double	ft_atoi_double(const char *str)
{
	int		sign;
	double	num;
	char	*s;

	s = skip_whitespace_signs(str);
	sign = extract_sign(str);
	num = extract_integer(s);
	return (sign * num);
}

/*
int	main(void) {
	const char *test_cases[] = {
		"12345",                      // 正の整数
		"-67890",                     // 負の整数
		"0",                          // ゼロ
		"   42",                      // 前置の空白
		"+100",                       // 正の符号付き整数
		"   -123  ",                  // 先頭と末尾の空白
		"abc123",                     // 非数値文字が含まれる
		"12abc34",                    // 数値の途中に非数値文字が含まれる
		"  - 789",                    // 無効な符号
		"2147483647",                 // INT_MAX
		"-2147483648",                // INT_MIN
		"999999999999",               // オーバーフローを起こす数値
		"-999999999999",              // オーバーフローを起こす負の数値
		"9223372036854775808",        // LONG_MAX + 1
		"9223372036854775806",        // LONG_MAX - 1
		"-9223372036854775807",       // LONG_MIN + 1
		"-9223372036854775809",       // LONG_MIN - 1
		"9999999999999999999999",     // LONG_MAX + 1
		"-999999999999999999999",     // LONG_MIN - n
	};

	int num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

	for (int i = 0; i < num_test_cases; i++) {
		const char *input = test_cases[i];
		int result = atoi(input);
		int result_ft = ft_atoi(input);
		printf("Input: \"%s\", atoi: %d, ft_atoi: %d\n", input, result,
			result_ft);
	}

	return (0);
}
 */