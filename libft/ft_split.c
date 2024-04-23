/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:18:22 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 18:07:22 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int i)
{
	while (i > 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	char	**new_str;

	i = -1;
	start = 0;
	if (s == NULL)
		return (NULL);
	new_str = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (new_str == NULL)
		return (NULL);
	while (++i < count_words(s, c))
	{
		while (s[start] == c)
			start++;
		new_str[i] = ft_substr(s, start, size_word(s, c, start));
		if (new_str[i] == NULL)
		{
			ft_free(new_str, i);
			return (NULL);
		}
		start += size_word(s, c, start);
	}
	new_str[i] = 0;
	return (new_str);
}

/* // テストケースを実行するヘルパー関数
void	test_ft_split(const char *input, char delimiter,
		const char **expected) {
	printf("Input: \"%s\", Delimiter: '%c'\n", input, delimiter);

	// ft_splitを呼び出して結果を取得
	char **result = ft_split(input, delimiter);

	// 結果の出力
	printf("Result:\n");
	for (int i = 0; expected[i] != NULL; i++) {
		printf("[%d] \"%s\"\n", i, result[i]);
	}

	// 期待値と比較
	int i = 0;
	while (expected[i] != NULL) {
		if (strcmp(result[i], expected[i]) != 0) {
			printf("Test Failed: Expected \"%s\", but got \"%s\"\n",
				expected[i], result[i]);
			break ;
		}
		i++;
	}

	// 結果のメモリ解放
	for (int i = 0; result[i] != NULL; i++) {
		free(result[i]);
	}
	free(result);

	printf("\n");
}

int	main(void) {
	// テストケース1: カンマで区切られた文字列
	const char *input1 = "hello,world,42,tokyo";
	const char *expected1[] = {"hello","world","42","tokyo", NULL};
	test_ft_split(input1, ',', expected1);

	// テストケース2: スペースで区切られた文字列
	const char *input2 = "This is a test";
	const char *expected2[] = {"This", "is", "a", "test", NULL};
	test_ft_split(input2, ' ', expected2);

	// テストケース3: 区切り文字が連続する場合
	const char *input3 = "A,,B,C,";
	const char *expected3[] = {"A", "B", "C", NULL};
	test_ft_split(input3, ',', expected3);

	// テストケース4: 区切り文字が文字列の先頭と末尾にある場合
	const char *input4 = ",Hello,World,";
	const char *expected4[] = {"Hello", "World", NULL};
	test_ft_split(input4, ',', expected4);

	return (0);
}
 */