/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:46:00 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/02 16:41:47 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_null(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s != NULL && s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen_null(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	while ((dstsize - (dst_len + i) > 1) && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/* #  include <stdio.h>
# include <stdlib.h>
# include <string.h>

int	main(void)
{
	int i;
	int j;

	char *dst1 = calloc(100, sizeof(char));
	//char *dst2 = calloc(100, sizeof(char));
	char dst2[0xF00] = "\0AAAAAAAAAAAAAAAA";
	i = ft_strlcat(dst1, "n\0AA", 100);
	j = strlcat(dst2, "n\0AA", 100);
	printf("%d, %d\n", i, j);
	i = ft_strlcat(dst1, "hello", 100);
	j = strlcat(dst2, "hello", 100);
	printf("%d, %d\n", i, j);
	i = ft_strlcat(dst1, "world", 100);
	j = strlcat(dst2, "world", 100);
	printf("%d, %d\n", i, j);
	char *src1 = calloc(100, sizeof(char));
	char *src2 = calloc(100, sizeof(char));
	for (int i = 0; i < 99; i++)
	{
		src1[i] = i + 1;
		src2[i] = i + 1;
	}
	printf("%d, %d\n", i, j);
	// i = ft_strlcat("nyan !", ((void *)0), 2);
	// j = strlcat("nyan !", ((void *)0), 2);
	i = ft_strlcat(dst1, src1, 10);
	j = strlcat(dst2, src2, 10);
	printf("%d, %d\n", i, j);
	i = ft_strlcat(dst1, src1, 50);
	j = strlcat(dst2, src2, 50);
	printf("%d, %d\n", i, j);
	i = ft_strlcat(dst1, src1, 100);
	j = strlcat(dst2, src2, 100);
	printf("%d, %d\n", i, j);
	i = ft_strlcat(dst1, src1, 10);
	j = strlcat(dst2, src2, 10);
	printf("%d, %d\n", i, j);
	return (0);
}
 */