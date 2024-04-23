/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:11:20 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 16:19:15 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	char		*s;
	size_t		i;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (s < d)
	{
		while (i < len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	return (dst);
}

/* int main() {
    // テストケース1
    unsigned char src[15] = "Hello, World!";
    unsigned char dst[20];
	unsigned char src_ft[15] = "Hello, World!";
    unsigned char dst_ft[20];
    memmove(dst, src, 15);
    ft_memmove(dst_ft, src_ft, 15);
    printf("memmove:%s, ft_memmove:%s\n", dst, dst_ft);

    // テストケース2
    unsigned char buffer[22] = "Hello, World!";
    unsigned char buffer_ft[22] = "Hello, World!";
    memmove(buffer + 6, buffer, 15);
    ft_memmove(buffer_ft + 6, buffer_ft, 15);
    printf("memmove:%s, ft_memmove:%s\n", buffer, buffer_ft);

	// テストケース3
    //memmove(NULL, buffer, 15);
    //ft_memmove(NULL, buffer_ft, 15);
	// memmove(buffer, NULL, 15);
    // ft_memmove(buffer_ft, NULL, 15);
	// memmove(NULL, NULL, 15);
    // ft_memmove(NULL, NULL, 15);
	// memmove(NULL, buffer, 0);
    // ft_memmove(NULL, buffer_ft, 0);
	// memmove(buffer, NULL, 0);
    // ft_memmove(buffer_ft, NULL, 0);
	// memmove(NULL, NULL, 0);
    // ft_memmove(NULL, NULL, 0);
    printf("memmove:%s, ft_memmove:%s\n", buffer, buffer_ft);

    return 0;
}
 */