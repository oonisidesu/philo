/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:08:18 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 13:08:37 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;
	size_t				i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
		i++;
	}
	return (0);
}

/* int main() {
    // テストケース1: 同じメモリ内容を比較
    unsigned char buffer1[] = {0x11, 0x22, 0x33, 0x44, 0x55};
    unsigned char buffer2[] = {0x11, 0x22, 0x33, 0x44, 0x55};
    size_t buffer_size = sizeof(buffer1);
    int result1 = memcmp(buffer1, buffer2, buffer_size);
    int result1_ft = ft_memcmp(buffer1, buffer2, buffer_size);
    printf("memcmp:%d, ft_memcmp:%d\n", result1, result1_ft);

    // テストケース2: 異なるメモリ内容を比較
    unsigned char buffer3[] = {0x11, 0x22, 0x33};
    unsigned char buffer4[] = {0x11, 0x22, 0x44};
    size_t buffer_size2 = sizeof(buffer3);
    int result2 = memcmp(buffer3, buffer4, buffer_size2);
    int result2_ft = ft_memcmp(buffer3, buffer4, buffer_size2);
    printf("memcmp:%d, ft_memcmp:%d\n", result2, result2_ft);

    // テストケース3: 部分的な比較
    unsigned char buffer5[] = {0x11, 0x22, 0x33, 0x44, 0x55};
    unsigned char buffer6[] = {0x11, 0x22, 0x66, 0x44, 0x55};
    size_t buffer_size3 = sizeof(buffer5);
    size_t compare_size = 3;
    int result3 = memcmp(buffer5, buffer6, compare_size);
    int result3_ft = ft_memcmp(buffer5, buffer6, compare_size);
    printf("memcmp:%d, ft_memcmp:%d\n", result3, result3_ft);

    // テストケース: NULL（size:0の時はエラーにならない）
    size_t compare_size4 = 100;
    // int result4 = memcmp(NULL, buffer6, compare_size);
    // int result4_ft = ft_memcmp(NULL, buffer6, compare_size);
    // int result4 = memcmp(buffer5, NULL, compare_size);
    // int result4_ft = ft_memcmp(buffer5, NULL, compare_size);
    // int result4 = memcmp(NULL, NULL, 0);
    // int result4_ft = ft_memcmp(NULL, NULL, 0);
    int result4 = memcmp(NULL, buffer6, 0);
    int result4_ft = ft_memcmp(NULL, buffer6, 0);
    printf("memcmp:%d, ft_memcmp:%d\n", result4, result4_ft);

    return 0;
}
 */