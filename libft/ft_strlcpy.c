/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:33:17 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:03:04 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/* int	main(void)
{
	char	src_ori[25] = "12131";
	char	dst_ori[0xF00];
	size_t	copied_ori;
	char	src_ft[25] = "12131";
	char	dst_ft[0xF00];
	size_t	copied_ft;

	printf("--orignal--\n");
	copied_ori = strlcpy(dst_ori, src_ori, sizeof(dst_ori));
	//copied_ori = strlcpy(NULL, NULL, 1);
	printf("Copied string: %s\n", dst_ori);
	printf("Number of bytes copied: %zu\n", copied_ori);
	printf("--ft--\n");
	copied_ft = ft_strlcpy(dst_ft, src_ft, sizeof(dst_ft));
	//copied_ft = ft_strlcpy(NULL, NULL, 1);
	printf("Copied string: %s\n", dst_ft);
	printf("Number of bytes copied: %zu\n", copied_ft);
	return (0);
}
 */