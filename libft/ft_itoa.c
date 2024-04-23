/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:11:14 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:54:10 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit_count(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	int_min_flag(int n)
{
	return (n == INT_MIN);
}

static void	conv_int_to_string(int n, char *new_str)
{
	int	i;

	i = get_digit_count(n) - 1;
	if (n < 0)
	{
		n *= -1;
		new_str[0] = '-';
	}
	while (new_str >= 0)
	{
		new_str[i] = '0' + (n % 10);
		if (n / 10 != 0)
		{
			n /= 10;
			i--;
		}
		else
			break ;
	}
}

char	*ft_itoa(int n)
{
	char	*new_str;
	int		new_str_maxlen;
	int		handle_n;

	new_str_maxlen = get_digit_count(n) + 1;
	new_str = (char *)malloc((new_str_maxlen) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_bzero(new_str, new_str_maxlen);
	handle_n = n;
	if (handle_n == INT_MIN)
		handle_n = INT_MIN + 1;
	conv_int_to_string(handle_n, new_str);
	new_str[new_str_maxlen - 1] = '\0';
	if (int_min_flag(n))
		new_str[new_str_maxlen - 2] = '8';
	return (new_str);
}

/* int main(void) {
    int test_cases[] = {12345, -67890, 0, INT_MAX, INT_MIN};
	int	test_cases_size = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < test_cases_size; i++) {
        int num = test_cases[i];
        char *result_ft = ft_itoa(num);
        // 結果を表示
        printf("Input: %d, ft_itoa: %s\n", num, result_ft);
        // メモリを解放
        free(result_ft);
    }

    return 0;
}
 */