/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:39:56 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:56:11 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)d);
}

/* int main(void) {
	// テストケース1: メモリコピーが正しく行われる場合
	char src[15] = "Hello, World!";
	char dst[20];
	char src_ft[16] = "Hello, World!";
	char dst_ft[20];
	size_t n = 14;  // NULL終端文字を含む
	memcpy(dst, src, n);
	ft_memcpy(dst_ft, src_ft, n);
	printf("memcpy:%s, ft_memcpy:%s\n", dst, dst_ft);

	// テストケース2: 部分的なメモリコピーが正しく行われる場合
	// char src2[15] = "Hello, World!";
	// char dst2[20];
	// char src2_ft[15] = "Hello, World!";
	// char dst2_ft[20];
	// size_t n2 = 5;  // 最初の5文字をコピー
	// memcpy(dst2, src2, n2);
	// ft_memcpy(dst2_ft, src2_ft, n2);
	// printf("memcpy:%s, ft_memcpy:%s\n", dst2, dst2_ft);

	// テストケース3: NULL終端文字のないメモリコピーが正しく行われる場合
	// char src3[15] = "Hello, World!";
	// char dst3[20];
	// char src3_ft[15] = "Hello, World!";
	// char dst3_ft[20];
	// size_t n3 = 14;
	// memcpy(dst3, src3, n3);
	// ft_memcpy(dst3_ft, src3_ft, n3);
	// printf("memcpy:%s, ft_memcpy:%s\n", dst3, dst3_ft);

	// テストケース
	// printf("memcpy:%s, ft_memcpy:%s\n", memcpy(NULL, NULL, 5),
		ft_memcpy(NULL, NULL, 5));
	//memcpy(NULL, src3, 5);
	//ft_memcpy(NULL, src3_ft, 5);
	//memcpy(dst3, NULL, 5);
	//ft_memcpy(dst3_ft, NULL, 5);

	// テストケース
	// char src4[15] = "Hello, World!";
	// char dst4[10];
	// //char src4_ft[15] = "Hello, World!";
	// //char dst4_ft[10];
	// size_t n4 = 100;
	// memcpy(dst4, src4, n4);
	// //ft_memcpy(dst4_ft, src4_ft, n4);
	// //printf("memcpy:%s, ft_memcpy:%s\n", dst4, dst4_ft);

	return (0);
}
 */