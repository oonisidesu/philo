/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:34:49 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:55:53 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*srch;
	size_t			i;

	srch = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (srch[i] == (unsigned char)c)
			return ((void *)(srch + i));
		i++;
	}
	return (NULL);
}

/* int main(void) {
	// テストケース1: メモリ内に存在する場合
	unsigned char buffer[] = {'a', 'b', 'c', 'd', 'e'};
	int search_value = 'c';
	size_t search_size = 3;
	void* result = memchr(buffer, search_value, search_size);
	void* result_ft = ft_memchr(buffer, search_value, search_size);
	printf("memchr:%s, ft_memchr:%s\n", (unsigned char*)result,
		(unsigned char*)result_ft);

	// テストケース2: メモリ内に存在しない場合
	unsigned char buffer2[] = {'a', 'b', 'c', 'd', 'e'};
	int search_value2 = 'f';
	size_t search_size2 = 3;
	void* result2 = memchr(buffer2, search_value2, search_size2);
	void* result2_ft = ft_memchr(buffer2, search_value2, search_size2);
	printf("memchr:%s, ft_memchr:%s\n", (unsigned char*)result2,
		(unsigned char*)result2_ft);

	// テストケース3: null
	//unsigned char buffer3[] = {'a', 'b', 'c', 'd', 'e'};
	int search_value3 = 'f';
	//size_t buffer_size3 = sizeof(buffer3);
	//size_t search_size3 = 0;
	size_t search_size3 = 10;
	//void* result3 = memchr(NULL, search_value3, search_size3);
	void* result3_ft = ft_memchr(NULL, search_value3, search_size3);
	//printf("memchr:%s, ft_memchr:%s\n", (unsigned char*)result3,
		(unsigned char*)result3_ft);

	return (0);
}
 */