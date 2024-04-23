/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:40:06 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:56:21 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	value;
	size_t			i;

	p = (unsigned char *)b;
	value = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		p[i] = value;
		i++;
	}
	return (b);
}

/* int	main(void)
{
	size_t			n1;
	int				c1;
	size_t			n1_ft;
	int				c1_ft;
	size_t			n2;
	int				c2;
	size_t			n2_ft;
	int				c2_ft;
	unsigned char	buffer1[10];
	unsigned char	buffer1_ft[10];
	unsigned char	buffer2[5];
	unsigned char	buffer2_ft[5];

	// テストケース1: メモリを0にセット
	n1 = sizeof(buffer1);
	c1 = 0;
	memset(buffer1, c1, n1);
	printf("memset 0 : ");
	for (size_t i = 0; i < n1; i++)
	{
		printf("%d ", buffer1[i]);
	}
	printf("\n");
	n1_ft = sizeof(buffer1_ft);
	c1_ft = 0;
	ft_memset(buffer1_ft, c1_ft, n1_ft);
	printf("ft_memset 0 : ");
	for (size_t i = 0; i < n1_ft; i++)
	{
		printf("%d ", buffer1_ft[i]);
	}
	printf("\n");
	// テストケース2: メモリをINT_MINにセット
	n2 = sizeof(buffer2);
	c2 = -2147483648;
	memset(buffer2, c2, n2);
	printf("memset 1 : ");
	for (size_t i = 0; i < n2; i++)
	{
		printf("%d ", buffer2[i]);
	}
	printf("\n");
	n2_ft = sizeof(buffer2_ft);
	c2_ft = -2147483648;
	ft_memset(buffer2_ft, c2_ft, n2_ft);
	printf("ft_memset 1 : ");
	for (size_t i = 0; i < n2_ft; i++)
	{
		printf("%d ", buffer2_ft[i]);
	}
	printf("\n");
	// テストケースNULL
	//memset(NULL, 2, 2);
	//ft_memset(NULL, 2, 2);
	memset(NULL, 0, 0);
	ft_memset(NULL, 0, 0);
	return (0);
}
 */